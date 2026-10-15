import socket
import ssl
import os
import base64
import hashlib
import struct

HOST = "echo.websocket.org"
PORT = 443
PATH = "/"
WS_MAGIC = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"
MAX_SHORT = 125


def generate_key():
    return base64.b64encode(os.urandom(16)).decode()


def compute_accept(key):
    return base64.b64encode(
        hashlib.sha1((key + WS_MAGIC).encode()).digest()
    ).decode()


def recv_exactly(sock, n):
    data = b""
    while len(data) < n:
        chunk = sock.recv(n - len(data))
        if not chunk:
            raise ConnectionError("Połączenie zamknięte")
        data += chunk
    return data


def recv_headers(sock):
    buf = b""
    while not buf.endswith(b"\r\n\r\n"):
        buf += sock.recv(1)
    return buf.decode(errors="replace")


def handshake(sock, host, path):
    key = generate_key()
    request = (
        f"GET {path} HTTP/1.1\r\n"
        f"Host: {host}\r\n"
        f"Upgrade: websocket\r\n"
        f"Connection: Upgrade\r\n"
        f"Sec-WebSocket-Key: {key}\r\n"
        f"Sec-WebSocket-Version: 13\r\n"
        f"\r\n"
    )
    sock.sendall(request.encode())
    response = recv_headers(sock)
    lines = response.split("\r\n")
    if "101" not in lines[0]:
        raise RuntimeError(f"Handshake nieudany: {lines[0]}")
    headers = {}
    for line in lines[1:]:
        if ": " in line:
            k, v = line.split(": ", 1)
            headers[k.lower()] = v.strip()
    expected = compute_accept(key)
    if headers.get("sec-websocket-accept", "") != expected:
        raise RuntimeError("Nieprawidłowy Sec-WebSocket-Accept")
    print(f"Handshake OK  (Sec-WebSocket-Accept: {expected})")


def send_text_short(sock, text):
    """Ramka tekstowa dla payload ≤ 125 bajtów — długość w jednym bajcie."""
    payload = text.encode("utf-8")
    assert len(payload) <= MAX_SHORT, f"Wiadomość za długa: {len(payload)} > {MAX_SHORT}"
    masking_key = os.urandom(4)
    # Byte 1: FIN=1, opcode=0x1 (text)
    # Byte 2: MASK=1, 7-bit length
    header = bytes([0x81, 0x80 | len(payload)])
    masked = bytes(b ^ masking_key[i % 4] for i, b in enumerate(payload))
    sock.sendall(header + masking_key + masked)


def recv_frame(sock):
    header = recv_exactly(sock, 2)
    byte1, byte2 = header[0], header[1]
    fin = bool(byte1 & 0x80)
    opcode = byte1 & 0x0F
    masked = bool(byte2 & 0x80)
    length = byte2 & 0x7F
    if length == 126:
        length = struct.unpack("!H", recv_exactly(sock, 2))[0]
    elif length == 127:
        length = struct.unpack("!Q", recv_exactly(sock, 8))[0]
    masking_key = recv_exactly(sock, 4) if masked else None
    payload = recv_exactly(sock, length)
    if masking_key:
        payload = bytes(b ^ masking_key[i % 4] for i, b in enumerate(payload))
    return fin, opcode, payload


def main():
    message = input(f"Wiadomość (max {MAX_SHORT} znaków): ").strip()
    if len(message.encode("utf-8")) > MAX_SHORT:
        print(f"Błąd: wiadomość przekracza {MAX_SHORT} bajtów.")
        return

    ctx = ssl.create_default_context()
    with socket.create_connection((HOST, PORT)) as raw:
        with ctx.wrap_socket(raw, server_hostname=HOST) as sock:
            handshake(sock, HOST, PATH)

            send_text_short(sock, message)
            print(f"Wysłano ({len(message.encode())} B): {message!r}")

            fin, opcode, payload = recv_frame(sock)
            if opcode == 0x1:
                print(f"Echo serwera ({len(payload)} B): {payload.decode()!r}")
            else:
                print(f"Odebrano ramkę opcode={opcode:#x}: {payload!r}")

            # Close (opcode 0x8, payload = status code 1000)
            mk = os.urandom(4)
            sc = struct.pack("!H", 1000)
            masked_sc = bytes(b ^ mk[i % 4] for i, b in enumerate(sc))
            sock.sendall(bytes([0x88, 0x82]) + mk + masked_sc)
            print("Połączenie zamknięte.")


if __name__ == "__main__":
    main()

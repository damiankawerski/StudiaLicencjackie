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


def send_frame(sock, payload, opcode=0x1):
    """Wyślij ramkę WebSocket dowolnej długości (klient: zawsze maskowana)."""
    if isinstance(payload, str):
        payload = payload.encode("utf-8")
    masking_key = os.urandom(4)
    length = len(payload)

    byte1 = 0x80 | opcode  # FIN=1

    if length <= 125:
        header = bytes([byte1, 0x80 | length])
    elif length <= 65535:
        header = bytes([byte1, 0x80 | 126]) + struct.pack("!H", length)
    else:
        header = bytes([byte1, 0x80 | 127]) + struct.pack("!Q", length)

    masked = bytes(b ^ masking_key[i % 4] for i, b in enumerate(payload))
    sock.sendall(header + masking_key + masked)
    return length


def recv_frame(sock):
    """Odbierz ramkę WebSocket (serwer nie maskuje)."""
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
    message = input("Wiadomość (dowolna długość): ")

    ctx = ssl.create_default_context()
    with socket.create_connection((HOST, PORT)) as raw:
        with ctx.wrap_socket(raw, server_hostname=HOST) as sock:
            handshake(sock, HOST, PATH)

            n = send_frame(sock, message)
            print(f"Wysłano ({n} B): {message[:80]!r}{'...' if len(message) > 80 else ''}")

            # Zbieraj fragmenty (FIN może nie być ustawiony od razu)
            full_payload = b""
            while True:
                fin, opcode, payload = recv_frame(sock)
                if opcode == 0x8:
                    print("Serwer zamknął połączenie.")
                    break
                full_payload += payload
                if fin:
                    break

            text = full_payload.decode(errors="replace")
            print(f"Echo serwera ({len(full_payload)} B): {text[:80]!r}"
                  f"{'...' if len(text) > 80 else ''}")

            # Wyślij Close
            mk = os.urandom(4)
            sc = struct.pack("!H", 1000)
            sock.sendall(bytes([0x88, 0x82]) + mk +
                         bytes(b ^ mk[i % 4] for i, b in enumerate(sc)))
            print("Połączenie zamknięte.")


if __name__ == "__main__":
    main()

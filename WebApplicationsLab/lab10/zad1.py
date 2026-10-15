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


def send_frame(sock, payload, opcode=0x1):
    if isinstance(payload, str):
        payload = payload.encode("utf-8")
    masking_key = os.urandom(4)
    length = len(payload)
    byte1 = 0x80 | opcode
    if length <= 125:
        header = bytes([byte1, 0x80 | length])
    elif length <= 65535:
        header = bytes([byte1, 0x80 | 126]) + struct.pack("!H", length)
    else:
        header = bytes([byte1, 0x80 | 127]) + struct.pack("!Q", length)
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
    key = generate_key()
    expected_accept = compute_accept(key)

    request = (
        f"GET {PATH} HTTP/1.1\r\n"
        f"Host: {HOST}\r\n"
        f"Upgrade: websocket\r\n"
        f"Connection: Upgrade\r\n"
        f"Sec-WebSocket-Key: {key}\r\n"
        f"Sec-WebSocket-Version: 13\r\n"
        f"\r\n"
    )

    ctx = ssl.create_default_context()
    with socket.create_connection((HOST, PORT)) as raw:
        with ctx.wrap_socket(raw, server_hostname=HOST) as sock:
            sock.sendall(request.encode())
            response = recv_headers(sock)

            print("=== Odpowiedź serwera ===")
            print(response.strip())
            print("========================\n")

            # Parsuj nagłówki
            lines = response.split("\r\n")
            status_line = lines[0]
            headers = {}
            for line in lines[1:]:
                if ": " in line:
                    k, v = line.split(": ", 1)
                    headers[k.lower()] = v.strip()

            if "101" not in status_line:
                raise RuntimeError(f"Handshake nieudany: {status_line}")

            actual_accept = headers.get("sec-websocket-accept", "")
            if actual_accept != expected_accept:
                raise RuntimeError(
                    f"Błędny Sec-WebSocket-Accept:\n"
                    f"  Oczekiwano: {expected_accept}\n"
                    f"  Otrzymano:  {actual_accept}"
                )

            print(f"Handshake zakończony sukcesem!")
            print(f"  Sec-WebSocket-Accept: {actual_accept} ✓")

            # Wyślij ramkę Close (opcode 0x8)
            send_frame(sock, struct.pack("!H", 1000), opcode=0x8)
            print("Wysłano ramkę Close.")


if __name__ == "__main__":
    main()

import socket
import os
import base64
import hashlib
import struct

HOST = "127.0.0.1"
PORT = 9001
WS_MAGIC = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"

OPCODES = {
    0x0: "continuation",
    0x1: "text",
    0x2: "binary",
    0x8: "close",
    0x9: "ping",
    0xA: "pong",
}


def recv_exactly(sock, n):
    data = b""
    while len(data) < n:
        chunk = sock.recv(n - len(data))
        if not chunk:
            raise ConnectionError("Połączenie zamknięte")
        data += chunk
    return data


def recv_http_headers(sock):
    buf = b""
    while not buf.endswith(b"\r\n\r\n"):
        byte = sock.recv(1)
        if not byte:
            break
        buf += byte
    return buf.decode(errors="replace")


def do_handshake(sock):
    raw = recv_http_headers(sock)
    lines = raw.split("\r\n")

    headers = {}
    for line in lines[1:]:
        if ": " in line:
            k, v = line.split(": ", 1)
            headers[k.lower()] = v.strip()

    ws_key = headers.get("sec-websocket-key", "")
    if not ws_key:
        sock.sendall(b"HTTP/1.1 400 Bad Request\r\n\r\n")
        raise RuntimeError("Brak Sec-WebSocket-Key")

    accept = base64.b64encode(
        hashlib.sha1((ws_key + WS_MAGIC).encode()).digest()
    ).decode()

    response = (
        "HTTP/1.1 101 Switching Protocols\r\n"
        "Upgrade: websocket\r\n"
        "Connection: Upgrade\r\n"
        f"Sec-WebSocket-Accept: {accept}\r\n"
        "\r\n"
    )
    sock.sendall(response.encode())
    print(f"  Handshake OK (key={ws_key[:10]}..., accept={accept[:10]}...)")


def recv_frame(sock):
    """Odbierz ramkę od klienta (klient maskuje)."""
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


def send_frame(sock, payload, opcode=0x1):
    """Wyślij ramkę do klienta (serwer nie maskuje)."""
    if isinstance(payload, str):
        payload = payload.encode("utf-8")
    length = len(payload)
    byte1 = 0x80 | opcode  # FIN=1

    if length <= 125:
        header = bytes([byte1, length])
    elif length <= 65535:
        header = bytes([byte1, 126]) + struct.pack("!H", length)
    else:
        header = bytes([byte1, 127]) + struct.pack("!Q", length)

    sock.sendall(header + payload)


def handle_client(conn, addr):
    print(f"Połączenie od {addr[0]}:{addr[1]}")
    try:
        do_handshake(conn)
        fragments = []

        while True:
            fin, opcode, payload = recv_frame(conn)
            name = OPCODES.get(opcode, f"0x{opcode:x}")
            print(f"  Ramka: opcode={name}, fin={fin}, len={len(payload)}")

            if opcode == 0x8:
                # Close — odpowiedz tym samym i zakończ
                send_frame(conn, payload, opcode=0x8)
                print("  Close handshake zakończony.")
                break

            elif opcode == 0x9:
                # Ping → Pong
                send_frame(conn, payload, opcode=0xA)
                print("  Pong wysłany.")

            elif opcode in (0x1, 0x2):
                # Nowa wiadomość
                fragments = [payload]
                if fin:
                    msg = b"".join(fragments)
                    text = msg.decode(errors="replace") if opcode == 0x1 else repr(msg)
                    print(f"  Wiadomość: {text[:80]!r}")
                    send_frame(conn, msg, opcode=opcode)

            elif opcode == 0x0:
                # Kontynuacja
                fragments.append(payload)
                if fin:
                    msg = b"".join(fragments)
                    first_opcode = 0x1  # zakładamy tekst
                    text = msg.decode(errors="replace")
                    print(f"  Złożona wiadomość: {text[:80]!r}")
                    send_frame(conn, msg, opcode=first_opcode)
                    fragments = []

            else:
                print(f"  Nieznana ramka opcode={opcode:#x}, ignoruję.")

    except (ConnectionError, OSError) as e:
        print(f"  Rozłączono: {e}")
    finally:
        conn.close()
        print(f"Zamknięto {addr[0]}:{addr[1]}\n")


def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        server.bind((HOST, PORT))
        server.listen(1)
        print(f"Serwer WebSocket nasłuchuje na ws://{HOST}:{PORT}/")
        print("Ctrl+C = stop\n")
        while True:
            conn, addr = server.accept()
            handle_client(conn, addr)


if __name__ == "__main__":
    main()

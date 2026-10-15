import socket
from urllib.parse import urlencode


HOST = "httpbin.org"
PORT = 80
PATH = "/post"


def recv_headers(sock):
    buf = b""
    while not buf.endswith(b"\r\n\r\n"):
        byte = sock.recv(1)
        if not byte:
            break
        buf += byte
    lines = buf.decode(errors="replace").split("\r\n")
    status_line = lines[0]
    headers = {}
    for line in lines[1:]:
        if ": " in line:
            k, v = line.split(": ", 1)
            headers[k.lower()] = v.strip()
    parts = status_line.split(" ", 2)
    status_code = int(parts[1]) if len(parts) >= 2 and parts[1].isdigit() else 0
    return status_code, headers, status_line


def recv_body(sock, headers):
    if headers.get("transfer-encoding", "").lower() == "chunked":
        body = b""
        while True:
            size_line = b""
            while not size_line.endswith(b"\r\n"):
                byte = sock.recv(1)
                if not byte:
                    return body
                size_line += byte
            chunk_size = int(size_line.strip(), 16)
            if chunk_size == 0:
                break
            chunk = b""
            while len(chunk) < chunk_size:
                data = sock.recv(chunk_size - len(chunk))
                if not data:
                    break
                chunk += data
            body += chunk
            sock.recv(2)
        return body
    if "content-length" in headers:
        size = int(headers["content-length"])
        body = b""
        while len(body) < size:
            data = sock.recv(size - len(body))
            if not data:
                break
            body += data
        return body
    body = b""
    while True:
        data = sock.recv(4096)
        if not data:
            break
        body += data
    return body


def main():
    print("Podaj dane formularza (puste pole = koniec):")
    fields = {}
    while True:
        key = input("  Klucz: ").strip()
        if not key:
            break
        value = input("  Wartość: ").strip()
        fields[key] = value

    if not fields:
        print("Nie podano żadnych danych.")
        return

    body = urlencode(fields).encode("utf-8")
    request = (
        f"POST {PATH} HTTP/1.1\r\n"
        f"Host: {HOST}\r\n"
        f"Content-Type: application/x-www-form-urlencoded\r\n"
        f"Content-Length: {len(body)}\r\n"
        f"Connection: close\r\n"
        f"\r\n"
    ).encode() + body

    print(f"\nWysyłanie: {fields}")
    with socket.create_connection((HOST, PORT)) as sock:
        sock.sendall(request)
        status_code, headers, status_line = recv_headers(sock)
        print(f"Status: {status_line}")
        response_body = recv_body(sock, headers)

    print("\nOdpowiedź serwera:")
    print(response_body.decode(errors="replace"))


if __name__ == "__main__":
    main()

import socket

HOST = "httpbin.org"
PORT = 80
PATH = "/image/png"
OUTPUT = "image.png"


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
    request = (
        f"GET {PATH} HTTP/1.1\r\n"
        f"Host: {HOST}\r\n"
        f"Accept: image/png,image/*;q=0.8,*/*;q=0.5\r\n"
        f"Connection: close\r\n"
        f"\r\n"
    )

    with socket.create_connection((HOST, PORT)) as sock:
        sock.sendall(request.encode())
        status_code, headers, status_line = recv_headers(sock)
        print(f"Status: {status_line}")
        print(f"Content-Type: {headers.get('content-type', 'N/A')}")
        print(f"Content-Length: {headers.get('content-length', 'N/A')}")
        body = recv_body(sock, headers)

    if status_code == 200:
        with open(OUTPUT, "wb") as f:
            f.write(body)
        print(f"Zapisano {len(body)} bajtów do {OUTPUT}")
    else:
        print(f"Błąd serwera: {status_code}")


if __name__ == "__main__":
    main()

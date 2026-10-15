# To nie zadziała bo serwer nie istnieje ale kod powinen być okej, nie mam jak przetestować
import socket

HOST = "212.182.24.27"
PORT = 8080
PATH = "/image.jpg"
OUTPUT = "image.jpg"


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


def get_file_size():
    request = (
        f"HEAD {PATH} HTTP/1.1\r\n"
        f"Host: {HOST}\r\n"
        f"Connection: close\r\n"
        f"\r\n"
    )
    with socket.create_connection((HOST, PORT)) as sock:
        sock.sendall(request.encode())
        status_code, headers, _ = recv_headers(sock)
    if status_code != 200:
        raise RuntimeError(f"HEAD nie powiodło się: {status_code}")
    if "content-length" not in headers:
        raise RuntimeError("Serwer nie zwrócił Content-Length")
    return int(headers["content-length"])


def fetch_range(start, end):
    request = (
        f"GET {PATH} HTTP/1.1\r\n"
        f"Host: {HOST}\r\n"
        f"Range: bytes={start}-{end}\r\n"
        f"Connection: close\r\n"
        f"\r\n"
    )
    with socket.create_connection((HOST, PORT)) as sock:
        sock.sendall(request.encode())
        status_code, headers, status_line = recv_headers(sock)
        print(f"  Część bytes={start}-{end}: {status_line}")
        if status_code not in (200, 206):
            raise RuntimeError(f"Błąd pobierania zakresu: {status_code}")
        return recv_body(sock, headers)


def main():
    print("Pobieranie rozmiaru pliku (HEAD)...")
    total_size = get_file_size()
    print(f"Rozmiar pliku: {total_size} bajtów")

    # Podziel na 3 części
    part = total_size // 3
    ranges = [
        (0,          part - 1),
        (part,       2 * part - 1),
        (2 * part,   total_size - 1),
    ]

    print("Pobieranie w 3 częściach...")
    parts = []
    for i, (start, end) in enumerate(ranges, 1):
        print(f"Pobieranie części {i}/3...")
        data = fetch_range(start, end)
        parts.append(data)
        print(f"  Odebrano {len(data)} bajtów")

    image = b"".join(parts)
    with open(OUTPUT, "wb") as f:
        f.write(image)
    print(f"\nZłożono obraz: {len(image)} bajtów → {OUTPUT}")


if __name__ == "__main__":
    main()

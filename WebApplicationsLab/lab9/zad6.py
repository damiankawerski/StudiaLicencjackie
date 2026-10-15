# Nie ma serwera znowu
import socket
import os
import json

HOST = "212.182.24.27"
PORT = 8080
PATH = "/image.jpg"
OUTPUT = "image.jpg"
META_FILE = "image.jpg.meta"


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


def get_file_size(extra_headers=""):
    request = (
        f"HEAD {PATH} HTTP/1.1\r\n"
        f"Host: {HOST}\r\n"
        f"{extra_headers}"
        f"Connection: close\r\n"
        f"\r\n"
    )
    with socket.create_connection((HOST, PORT)) as sock:
        sock.sendall(request.encode())
        return recv_headers(sock)


def fetch_range(start, end, extra_headers=""):
    request = (
        f"GET {PATH} HTTP/1.1\r\n"
        f"Host: {HOST}\r\n"
        f"Range: bytes={start}-{end}\r\n"
        f"{extra_headers}"
        f"Connection: close\r\n"
        f"\r\n"
    )
    with socket.create_connection((HOST, PORT)) as sock:
        sock.sendall(request.encode())
        status_code, headers, status_line = recv_headers(sock)
        if status_code not in (200, 206):
            return status_code, headers, b""
        return status_code, headers, recv_body(sock, headers)


def load_meta():
    if os.path.exists(META_FILE):
        with open(META_FILE) as f:
            return json.load(f)
    return {}


def save_meta(meta):
    with open(META_FILE, "w") as f:
        json.dump(meta, f)


def main():
    meta = load_meta()
    last_modified = meta.get("last-modified", "")
    etag = meta.get("etag", "")

    # Warunkowy HEAD z If-Modified-Since / If-None-Match
    cond_headers = ""
    if last_modified:
        cond_headers += f"If-Modified-Since: {last_modified}\r\n"
    if etag:
        cond_headers += f"If-None-Match: {etag}\r\n"

    print("Sprawdzanie czy plik się zmienił (HEAD)...")
    status_code, head_headers, status_line = get_file_size(cond_headers)
    print(f"Odpowiedź HEAD: {status_line}")

    if status_code == 304:
        print("Plik nie zmienił się (304 Not Modified). Pobieranie pominięte.")
        return

    if status_code != 200:
        print(f"Błąd: {status_code}")
        return

    total_size = int(head_headers.get("content-length", 0))
    new_last_modified = head_headers.get("last-modified", "")
    new_etag = head_headers.get("etag", "")
    print(f"Rozmiar: {total_size} B, Last-Modified: {new_last_modified}")

    # Pobieranie w 3 częściach
    part = total_size // 3
    ranges = [
        (0,        part - 1),
        (part,     2 * part - 1),
        (2 * part, total_size - 1),
    ]

    print("Pobieranie w 3 częściach...")
    parts = []
    for i, (start, end) in enumerate(ranges, 1):
        sc, hdrs, data = fetch_range(start, end, cond_headers)
        print(f"  Część {i}/3 bytes={start}-{end}: {len(data)} B")
        parts.append(data)

    image = b"".join(parts)
    with open(OUTPUT, "wb") as f:
        f.write(image)
    print(f"Zapisano {len(image)} B → {OUTPUT}")

    # Zaktualizuj metadane
    save_meta({"last-modified": new_last_modified, "etag": new_etag})
    print(f"Zaktualizowano metadane ({META_FILE})")


if __name__ == "__main__":
    main()

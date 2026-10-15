import socket
import os
import mimetypes
from datetime import datetime, timezone

HOST = "127.0.0.1"
PORT = 8000
WWW_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "www")

MIME_TYPES = {
    ".html": "text/html; charset=utf-8",
    ".css":  "text/css",
    ".js":   "application/javascript",
    ".png":  "image/png",
    ".jpg":  "image/jpeg",
    ".jpeg": "image/jpeg",
    ".gif":  "image/gif",
    ".ico":  "image/x-icon",
    ".txt":  "text/plain; charset=utf-8",
}

STATUS = {
    200: "OK",
    404: "Not Found",
    405: "Method Not Allowed",
    500: "Internal Server Error",
}


def recv_request(sock):
    buf = b""
    while not buf.endswith(b"\r\n\r\n"):
        byte = sock.recv(1)
        if not byte:
            break
        buf += byte
    return buf.decode(errors="replace")


def parse_request(raw):
    lines = raw.split("\r\n")
    if not lines:
        return None, None, {}
    parts = lines[0].split(" ", 2)
    if len(parts) < 2:
        return None, None, {}
    method = parts[0].upper()
    path = parts[1]
    headers = {}
    for line in lines[1:]:
        if ": " in line:
            k, v = line.split(": ", 1)
            headers[k.lower()] = v.strip()
    return method, path, headers


def send_response(sock, status_code, headers, body=b""):
    status_text = STATUS.get(status_code, "Unknown")
    date_str = datetime.now(timezone.utc).strftime("%a, %d %b %Y %H:%M:%S GMT")
    response = (
        f"HTTP/1.1 {status_code} {status_text}\r\n"
        f"Date: {date_str}\r\n"
        f"Server: PythonHTTP/1.0\r\n"
        f"Content-Length: {len(body)}\r\n"
        f"Connection: close\r\n"
    )
    for k, v in headers.items():
        response += f"{k}: {v}\r\n"
    response += "\r\n"
    sock.sendall(response.encode() + body)


def resolve_path(url_path):
    # Zapobiegaj directory traversal
    url_path = url_path.split("?")[0]  # usuń query string
    if url_path == "/" or url_path == "":
        url_path = "/index.html"
    safe_path = os.path.normpath(url_path.lstrip("/"))
    full_path = os.path.join(WWW_DIR, safe_path)
    # Upewnij się że jesteśmy w WWW_DIR
    if not os.path.abspath(full_path).startswith(os.path.abspath(WWW_DIR)):
        return None
    return full_path


def handle_client(conn, addr):
    try:
        raw = recv_request(conn)
        if not raw.strip():
            return

        method, path, req_headers = parse_request(raw)
        if method is None:
            return

        timestamp = datetime.now().strftime("%H:%M:%S")
        print(f"[{timestamp}] {addr[0]} {method} {path}")

        if method not in ("GET", "HEAD"):
            body = b"Method Not Allowed"
            send_response(conn, 405, {"Content-Type": "text/plain", "Allow": "GET, HEAD"}, body)
            return

        full_path = resolve_path(path)
        if full_path is None or not os.path.isfile(full_path):
            error_path = os.path.join(WWW_DIR, "404.html")
            if os.path.isfile(error_path):
                with open(error_path, "rb") as f:
                    body = f.read()
                content_type = "text/html; charset=utf-8"
            else:
                body = b"<h1>404 Not Found</h1>"
                content_type = "text/html; charset=utf-8"
            send_response(conn, 404, {"Content-Type": content_type}, body if method == "GET" else b"")
            return

        ext = os.path.splitext(full_path)[1].lower()
        content_type = MIME_TYPES.get(ext, "application/octet-stream")

        with open(full_path, "rb") as f:
            body = f.read()

        extra = {"Content-Type": content_type}
        send_response(conn, 200, extra, body if method == "GET" else b"")

    except Exception as e:
        print(f"Błąd obsługi klienta: {e}")
    finally:
        conn.close()


def main():
    print(f"Serwer HTTP: http://{HOST}:{PORT}/")
    print(f"Katalog plików: {WWW_DIR}")
    print("Ctrl+C = stop\n")

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        server.bind((HOST, PORT))
        server.listen(5)
        while True:
            conn, addr = server.accept()
            handle_client(conn, addr)


if __name__ == "__main__":
    main()

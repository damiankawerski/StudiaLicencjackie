import socket
import ssl
import re

IMAP_HOST = "imap.interia.pl"
IMAP_PORT = 993
USER = "damian.kawerski@interia.pl"
PASSWORD = "eBr#pLJy96wRbam"

_tag_n = 0


def next_tag():
    global _tag_n
    _tag_n += 1
    return f"A{_tag_n}"


def recv_line(sock):
    buf = b""
    while not buf.endswith(b"\r\n"):
        chunk = sock.recv(1)
        if not chunk:
            break
        buf += chunk
    return buf.decode(errors="replace").strip()


def send_cmd(sock, tag, cmd):
    sock.sendall(f"{tag} {cmd}\r\n".encode())


def read_response(sock, tag):
    lines = []
    while True:
        line = recv_line(sock)
        lines.append(line)
        if line.startswith(tag + " "):
            break
    return lines


def check_ok(lines, context=""):
    last = lines[-1]
    parts = last.split(" ", 2)
    if len(parts) < 2 or parts[1] != "OK":
        raise RuntimeError(f"Błąd serwera [{context}]: {last}")


def delete_message():
    ctx = ssl.create_default_context()
    with socket.create_connection((IMAP_HOST, IMAP_PORT)) as raw:
        with ctx.wrap_socket(raw, server_hostname=IMAP_HOST) as sock:
            recv_line(sock)  # powitanie

            tag = next_tag()
            send_cmd(sock, tag, f'LOGIN {USER} "{PASSWORD}"')
            check_ok(read_response(sock, tag), "LOGIN")

            # Wybierz INBOX
            tag = next_tag()
            send_cmd(sock, tag, "SELECT INBOX")
            lines = read_response(sock, tag)
            check_ok(lines, "SELECT INBOX")

            exists = 0
            for line in lines:
                m = re.match(r'\* (\d+) EXISTS', line)
                if m:
                    exists = int(m.group(1))
            print(f"INBOX zawiera {exists} wiadomości.")

            if exists == 0:
                print("Brak wiadomości do usunięcia.")
                return

            # Pokaż flagi wszystkich wiadomości
            tag = next_tag()
            send_cmd(sock, tag, "FETCH 1:* (FLAGS)")
            lines = read_response(sock, tag)
            check_ok(lines, "FETCH FLAGS")
            for line in lines[:-1]:
                if "FETCH" in line:
                    print(line)

            msg_num = int(input(f"\nNumer wiadomości do usunięcia (1-{exists}): ").strip())
            if msg_num < 1 or msg_num > exists:
                print("Nieprawidłowy numer wiadomości.")
                return

            # Oznacz wiadomość flagą \Deleted
            tag = next_tag()
            send_cmd(sock, tag, rf"STORE {msg_num} +FLAGS \Deleted")
            check_ok(read_response(sock, tag), "STORE")
            print(f"Wiadomość nr {msg_num} oznaczona jako \\Deleted.")

            # Fizycznie usuń wiadomość
            tag = next_tag()
            send_cmd(sock, tag, "EXPUNGE")
            lines = read_response(sock, tag)
            check_ok(lines, "EXPUNGE")
            for line in lines[:-1]:
                if "EXPUNGE" in line:
                    print(line)
            print("Wiadomość fizycznie usunięta (EXPUNGE).")

            tag = next_tag()
            send_cmd(sock, tag, "LOGOUT")
            read_response(sock, tag)


if __name__ == "__main__":
    delete_message()

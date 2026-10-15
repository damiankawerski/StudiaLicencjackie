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


def quote_mailbox(name):
    if " " in name or not name:
        return f'"{name}"'
    return name


def parse_mailboxes(lines):
    mailboxes = []
    for line in lines:
        if not line.startswith("* LIST"):
            continue
        m = re.match(r'\* LIST \([^)]*\) (?:NIL|"[^"]+"|\S+) (.+)$', line)
        if m:
            name = m.group(1).strip()
            if name.startswith('"') and name.endswith('"'):
                name = name[1:-1]
            mailboxes.append(name)
    return mailboxes


def total_message_count():
    ctx = ssl.create_default_context()
    with socket.create_connection((IMAP_HOST, IMAP_PORT)) as raw:
        with ctx.wrap_socket(raw, server_hostname=IMAP_HOST) as sock:
            recv_line(sock)  # powitanie

            tag = next_tag()
            send_cmd(sock, tag, f'LOGIN {USER} "{PASSWORD}"')
            check_ok(read_response(sock, tag), "LOGIN")

            tag = next_tag()
            send_cmd(sock, tag, 'LIST "" *')
            lines = read_response(sock, tag)
            check_ok(lines, "LIST")
            mailboxes = parse_mailboxes(lines)

            total = 0
            for mailbox in mailboxes:
                tag = next_tag()
                send_cmd(sock, tag, f"STATUS {quote_mailbox(mailbox)} (MESSAGES)")
                resp = read_response(sock, tag)
                try:
                    check_ok(resp, f"STATUS {mailbox}")
                    for line in resp:
                        if line.upper().startswith("* STATUS"):
                            m = re.search(r"MESSAGES (\d+)", line, re.IGNORECASE)
                            if m:
                                count = int(m.group(1))
                                total += count
                                print(f"  {mailbox}: {count} wiadomości")
                except RuntimeError:
                    pass  # pomijamy skrzynki bez dostępu

            print(f"\nŁączna liczba wiadomości we wszystkich skrzynkach: {total}")

            tag = next_tag()
            send_cmd(sock, tag, "LOGOUT")
            read_response(sock, tag)


if __name__ == "__main__":
    total_message_count()

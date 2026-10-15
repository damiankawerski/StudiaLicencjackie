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


def main():
    ctx = ssl.create_default_context()
    with socket.create_connection((IMAP_HOST, IMAP_PORT)) as raw:
        with ctx.wrap_socket(raw, server_hostname=IMAP_HOST) as sock:
            greeting = recv_line(sock)
            print(f"Powitanie: {greeting}\n")

            # Logowanie
            tag = next_tag()
            send_cmd(sock, tag, f'LOGIN {USER} "{PASSWORD}"')
            lines = read_response(sock, tag)
            check_ok(lines, "LOGIN")
            print("Zalogowano pomyślnie.\n")

            # Lista wszystkich skrzynek
            tag = next_tag()
            send_cmd(sock, tag, 'LIST "" *')
            lines = read_response(sock, tag)
            check_ok(lines, "LIST")
            mailboxes = parse_mailboxes(lines)
            print(f"Znalezione skrzynki: {mailboxes}\n")

            # Liczba wiadomości w każdej skrzynce
            print("Liczba wiadomości w poszczególnych skrzynkach:")
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
                                print(f"  {mailbox}: {m.group(1)} wiadomości")
                except RuntimeError as e:
                    print(f"  {mailbox}: błąd - {e}")

            # Wybór skrzynki INBOX
            tag = next_tag()
            send_cmd(sock, tag, "SELECT INBOX")
            lines = read_response(sock, tag)
            check_ok(lines, "SELECT INBOX")

            exists = 0
            for line in lines:
                m = re.match(r'\* (\d+) EXISTS', line)
                if m:
                    exists = int(m.group(1))
            print(f"\nINBOX: {exists} wiadomości.\n")

            if exists == 0:
                print("Brak wiadomości do pobrania.")
            else:
                # Pobranie pierwszej wiadomości
                tag = next_tag()
                send_cmd(sock, tag, "FETCH 1 BODY[]")
                lines = read_response(sock, tag)
                check_ok(lines, "FETCH 1")
                print("--- Pierwsza wiadomość ---")
                for line in lines[:-1]:
                    print(line)
                print("--- Koniec wiadomości ---\n")

                # Oznacz pierwszą wiadomość jako przeczytaną
                tag = next_tag()
                send_cmd(sock, tag, r"STORE 1 +FLAGS \Seen")
                lines = read_response(sock, tag)
                check_ok(lines, "STORE")
                print("Wiadomość nr 1 oznaczona jako przeczytana (\\Seen).")

            # Wylogowanie
            tag = next_tag()
            send_cmd(sock, tag, "LOGOUT")
            read_response(sock, tag)
            print("Wylogowano.")


if __name__ == "__main__":
    main()

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


def show_and_mark_unread():
    ctx = ssl.create_default_context()
    with socket.create_connection((IMAP_HOST, IMAP_PORT)) as raw:
        with ctx.wrap_socket(raw, server_hostname=IMAP_HOST) as sock:
            recv_line(sock)  # powitanie

            tag = next_tag()
            send_cmd(sock, tag, f'LOGIN {USER} "{PASSWORD}"')
            check_ok(read_response(sock, tag), "LOGIN")

            # Wybierz skrzynkę INBOX
            tag = next_tag()
            send_cmd(sock, tag, "SELECT INBOX")
            check_ok(read_response(sock, tag), "SELECT INBOX")

            # Szukaj nieprzeczytanych wiadomości
            tag = next_tag()
            send_cmd(sock, tag, "SEARCH UNSEEN")
            lines = read_response(sock, tag)
            check_ok(lines, "SEARCH UNSEEN")

            unread_ids = []
            for line in lines:
                if line.startswith("* SEARCH"):
                    parts = line.split()[2:]
                    unread_ids = [int(p) for p in parts if p.isdigit()]
                    break

            if not unread_ids:
                print("Brak nieprzeczytanych wiadomości w skrzynce INBOX.")
            else:
                print(f"Nieprzeczytane wiadomości ({len(unread_ids)}): {unread_ids}\n")

                # Wyświetl treść każdej nieprzeczytanej wiadomości
                for msg_id in unread_ids:
                    tag = next_tag()
                    send_cmd(sock, tag, f"FETCH {msg_id} BODY[TEXT]")
                    lines = read_response(sock, tag)
                    check_ok(lines, f"FETCH {msg_id}")
                    print(f"--- Treść wiadomości nr {msg_id} ---")
                    for line in lines[:-1]:
                        print(line)
                    print(f"--- Koniec wiadomości nr {msg_id} ---\n")

                # Oznacz wszystkie nieprzeczytane jako przeczytane
                ids_str = ",".join(str(i) for i in unread_ids)
                tag = next_tag()
                send_cmd(sock, tag, rf"STORE {ids_str} +FLAGS \Seen")
                check_ok(read_response(sock, tag), "STORE")
                print(f"Wiadomości {unread_ids} oznaczone jako przeczytane (\\Seen).")

            tag = next_tag()
            send_cmd(sock, tag, "LOGOUT")
            read_response(sock, tag)


if __name__ == "__main__":
    show_and_mark_unread()

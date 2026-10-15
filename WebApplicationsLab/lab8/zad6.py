import socket
import re
import copy

HOST = "127.0.0.1"
PORT = 1430

# Symulowane wiadomości (nagłówki + pusta linia + treść)
_INITIAL_MESSAGES = {
    "INBOX": [
        {
            "uid": 1,
            "flags": {"\\Seen"},
            "full": (
                "From: jan.kowalski@example.com\r\n"
                "To: user@example.com\r\n"
                "Subject: Pierwsza wiadomosc testowa\r\n"
                "Date: Mon, 20 May 2024 10:00:00 +0000\r\n"
                "\r\n"
                "Tresc pierwszej wiadomosci testowej.\r\n"
                "To jest wiadomosc numer 1.\r\n"
            ),
        },
        {
            "uid": 2,
            "flags": set(),
            "full": (
                "From: anna.nowak@example.com\r\n"
                "To: user@example.com\r\n"
                "Subject: Druga wiadomosc testowa\r\n"
                "Date: Tue, 21 May 2024 11:00:00 +0000\r\n"
                "\r\n"
                "Tresc drugiej wiadomosci testowej.\r\n"
                "To jest wiadomosc numer 2.\r\n"
            ),
        },
        {
            "uid": 3,
            "flags": set(),
            "full": (
                "From: test.sender@example.com\r\n"
                "To: user@example.com\r\n"
                "Subject: Trzecia wiadomosc testowa\r\n"
                "Date: Wed, 22 May 2024 12:00:00 +0000\r\n"
                "\r\n"
                "Tresc trzeciej wiadomosci testowej.\r\n"
                "To jest wiadomosc numer 3.\r\n"
            ),
        },
    ],
    "Sent": [
        {
            "uid": 1,
            "flags": {"\\Seen"},
            "full": (
                "From: user@example.com\r\n"
                "To: odbiorca@example.com\r\n"
                "Subject: Wyslana wiadomosc\r\n"
                "Date: Thu, 23 May 2024 09:00:00 +0000\r\n"
                "\r\n"
                "Tresc wyslane wiadomosci.\r\n"
            ),
        }
    ],
    "Trash": [],
}


def parse_seq_set(seq_set_str, count):
    ids = []
    for part in seq_set_str.split(","):
        if ":" in part:
            a, b = part.split(":", 1)
            start = int(a)
            end = count if b == "*" else int(b)
            ids.extend(range(start, end + 1))
        elif part == "*":
            if count > 0:
                ids.append(count)
        else:
            try:
                ids.append(int(part))
            except ValueError:
                pass
    return sorted(set(ids))


def _msg_headers(full):
    if "\r\n\r\n" in full:
        return full.split("\r\n\r\n", 1)[0] + "\r\n\r\n"
    return full


def _msg_body(full):
    if "\r\n\r\n" in full:
        return full.split("\r\n\r\n", 1)[1]
    return ""


def handle_client(conn):
    state = "NOT_AUTH"
    selected = None
    messages = []

    def send(text):
        conn.sendall(text.encode("utf-8", errors="replace"))

    def recv_line():
        buf = b""
        while not buf.endswith(b"\r\n"):
            chunk = conn.recv(1)
            if not chunk:
                return None
            buf += chunk
        return buf.decode(errors="replace").strip()

    send("* OK [CAPABILITY IMAP4rev1] Serwer IMAP gotowy\r\n")

    while True:
        line = recv_line()
        if line is None:
            break

        parts = line.split(None, 2)
        if len(parts) < 2:
            continue

        tag = parts[0]
        cmd = parts[1].upper()
        args = parts[2] if len(parts) > 2 else ""

        print(f"< {line}")

        if cmd == "LOGIN":
            # Akceptujemy dowolne dane logowania
            state = "AUTH"
            send(f"{tag} OK Logged in\r\n")

        elif cmd == "LIST":
            if state == "NOT_AUTH":
                send(f"{tag} BAD Not authenticated\r\n")
                continue
            for mbox in _INITIAL_MESSAGES:
                has_children = any(
                    m.startswith(mbox + ".") for m in _INITIAL_MESSAGES if m != mbox
                )
                attrs = "\\HasChildren" if has_children else "\\HasNoChildren"
                send(f'* LIST ({attrs}) "/" {mbox}\r\n')
            send(f"{tag} OK LIST completed\r\n")

        elif cmd == "STATUS":
            if state == "NOT_AUTH":
                send(f"{tag} BAD Not authenticated\r\n")
                continue
            m = re.match(r'"?([^"(]+?)"?\s+\(([^)]+)\)', args)
            if not m:
                send(f"{tag} BAD Invalid STATUS syntax\r\n")
                continue
            mbox_name = m.group(1).strip()
            items = m.group(2).upper().split()
            if mbox_name not in _INITIAL_MESSAGES:
                send(f"{tag} NO Mailbox does not exist\r\n")
                continue
            db_msgs = _INITIAL_MESSAGES[mbox_name]
            result_parts = []
            for item in items:
                if item == "MESSAGES":
                    result_parts.append(f"MESSAGES {len(db_msgs)}")
                elif item == "UNSEEN":
                    u = sum(1 for msg in db_msgs if "\\Seen" not in msg["flags"])
                    result_parts.append(f"UNSEEN {u}")
                elif item == "RECENT":
                    result_parts.append("RECENT 0")
                elif item == "UIDNEXT":
                    result_parts.append(f"UIDNEXT {len(db_msgs) + 1}")
                elif item == "UIDVALIDITY":
                    result_parts.append("UIDVALIDITY 1")
            send(f"* STATUS {mbox_name} ({' '.join(result_parts)})\r\n")
            send(f"{tag} OK STATUS completed\r\n")

        elif cmd == "SELECT":
            if state == "NOT_AUTH":
                send(f"{tag} BAD Not authenticated\r\n")
                continue
            mbox_name = args.strip().strip('"')
            if mbox_name not in _INITIAL_MESSAGES:
                send(f"{tag} NO Mailbox does not exist\r\n")
                continue
            selected = mbox_name
            messages = copy.deepcopy(_INITIAL_MESSAGES[mbox_name])
            state = "SELECTED"
            send("* FLAGS (\\Answered \\Flagged \\Deleted \\Seen \\Draft)\r\n")
            send("* OK [PERMANENTFLAGS (\\Answered \\Flagged \\Deleted \\Seen \\Draft \\*)] Flags permitted.\r\n")
            send(f"* {len(messages)} EXISTS\r\n")
            send("* 0 RECENT\r\n")
            send("* OK [UIDVALIDITY 1] UIDs valid\r\n")
            send(f"* OK [UIDNEXT {len(messages) + 1}] Predicted next UID\r\n")
            send(f"{tag} OK [READ-WRITE] SELECT completed\r\n")

        elif cmd == "SEARCH":
            if state != "SELECTED":
                send(f"{tag} BAD No mailbox selected\r\n")
                continue
            criteria = args.strip().upper()
            matching = []
            for i, msg in enumerate(messages, 1):
                if criteria == "ALL":
                    matching.append(i)
                elif criteria in ("UNSEEN", "NEW"):
                    if "\\Seen" not in msg["flags"]:
                        matching.append(i)
                elif criteria == "SEEN":
                    if "\\Seen" in msg["flags"]:
                        matching.append(i)
                elif criteria.startswith("BODY "):
                    text = criteria.split(None, 1)[1].strip('"')
                    if text in msg["full"].upper():
                        matching.append(i)
                elif criteria.startswith("FROM "):
                    addr = criteria.split(None, 1)[1].strip('"')
                    if addr in msg["full"].upper():
                        matching.append(i)
                else:
                    matching.append(i)
            ids_str = " ".join(str(i) for i in matching)
            send(f"* SEARCH {ids_str}\r\n")
            send(f"{tag} OK SEARCH completed\r\n")

        elif cmd == "FETCH":
            if state != "SELECTED":
                send(f"{tag} BAD No mailbox selected\r\n")
                continue
            fetch_parts = args.split(None, 1)
            if len(fetch_parts) < 2:
                send(f"{tag} BAD Invalid FETCH syntax\r\n")
                continue
            seq_str = fetch_parts[0]
            data_spec = fetch_parts[1].upper()
            msg_ids = parse_seq_set(seq_str, len(messages))

            for seq_num in msg_ids:
                if seq_num < 1 or seq_num > len(messages):
                    continue
                msg = messages[seq_num - 1]
                flags_str = " ".join(msg["flags"])

                if "BODY[]" in data_spec:
                    literal = msg["full"]
                    size = len(literal.encode("utf-8"))
                    send(f"* {seq_num} FETCH (BODY[] {{{size}}}\r\n")
                    send(literal)
                    send(")\r\n")
                    msg["flags"].add("\\Seen")
                elif "BODY[TEXT]" in data_spec:
                    body = _msg_body(msg["full"])
                    size = len(body.encode("utf-8"))
                    send(f"* {seq_num} FETCH (BODY[TEXT] {{{size}}}\r\n")
                    send(body)
                    send(")\r\n")
                    msg["flags"].add("\\Seen")
                elif "BODY[HEADER]" in data_spec:
                    headers = _msg_headers(msg["full"])
                    size = len(headers.encode("utf-8"))
                    send(f"* {seq_num} FETCH (BODY[HEADER] {{{size}}}\r\n")
                    send(headers)
                    send(")\r\n")
                else:
                    # Domyślnie: zwróć flagi
                    send(f"* {seq_num} FETCH (FLAGS ({flags_str}))\r\n")

            send(f"{tag} OK FETCH completed\r\n")

        elif cmd == "STORE":
            if state != "SELECTED":
                send(f"{tag} BAD No mailbox selected\r\n")
                continue
            store_parts = args.split(None, 2)
            if len(store_parts) < 3:
                send(f"{tag} BAD Invalid STORE syntax\r\n")
                continue
            seq_str = store_parts[0]
            action = store_parts[1].upper()
            flags_raw = store_parts[2].strip("() ")
            new_flags = set(flags_raw.split())
            msg_ids = parse_seq_set(seq_str, len(messages))

            for seq_num in msg_ids:
                if seq_num < 1 or seq_num > len(messages):
                    continue
                msg = messages[seq_num - 1]
                if "+FLAGS" in action:
                    msg["flags"].update(new_flags)
                elif "-FLAGS" in action:
                    msg["flags"] -= new_flags
                else:
                    msg["flags"] = new_flags.copy()
                if "SILENT" not in action:
                    flags_str = " ".join(msg["flags"])
                    send(f"* {seq_num} FETCH (FLAGS ({flags_str}))\r\n")

            send(f"{tag} OK STORE completed\r\n")

        elif cmd == "EXPUNGE":
            if state != "SELECTED":
                send(f"{tag} BAD No mailbox selected\r\n")
                continue
            to_delete = [
                i + 1 for i, msg in enumerate(messages) if "\\Deleted" in msg["flags"]
            ]
            for seq_num in reversed(to_delete):
                send(f"* {seq_num} EXPUNGE\r\n")
            messages = [msg for msg in messages if "\\Deleted" not in msg["flags"]]
            send(f"{tag} OK EXPUNGE completed\r\n")

        elif cmd == "CLOSE":
            if state != "SELECTED":
                send(f"{tag} BAD No mailbox selected\r\n")
                continue
            messages = [msg for msg in messages if "\\Deleted" not in msg["flags"]]
            selected = None
            state = "AUTH"
            send(f"{tag} OK CLOSE completed\r\n")

        elif cmd == "LOGOUT":
            send("* BYE Logging out\r\n")
            send(f"{tag} OK LOGOUT completed\r\n")
            break

        else:
            send(f"{tag} BAD Komenda nie jest zaimplementowana: {cmd}\r\n")

    conn.close()


def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        server.bind((HOST, PORT))
        server.listen(1)
        print(f"Serwer IMAP nasłuchuje na {HOST}:{PORT}")
        print("Skrzynki: INBOX (3 wiad.), Sent (1 wiad.), Trash (0 wiad.)")
        print("Naciśnij Ctrl+C, aby zatrzymać.\n")
        while True:
            conn, addr = server.accept()
            print(f"Połączenie od {addr[0]}:{addr[1]}")
            handle_client(conn)
            print(f"Rozłączono {addr[0]}:{addr[1]}\n")


if __name__ == "__main__":
    main()

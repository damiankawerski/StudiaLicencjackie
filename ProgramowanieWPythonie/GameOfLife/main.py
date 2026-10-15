import curses
import random
def initialize_grid(height,width):
    """
    Tworzy losową planszę do gry.
    Zwraca: lista 2D (tablica) zawierająca 0 i 1, gdzie 1 oznacza żywą komórkę.
    """
    return [[random.choice([0,1])for _ in range(width)]for _ in range(height)]


def count_neighbors(grid, x, y):
    """
    Zlicza liczbę żywych sąsiadów dla komórki (x, y).
    Zwraca: liczba całkowita - ilość żywych sąsiadów.
    """
    # Zaimplementować tę funkcję
    height = len(grid)  # liczba wierszy (y)
    length = len(grid[0])  # liczba kolumn (x)
    count = 0

    for i in [-1, 0, 1]:
        for j in [-1, 0, 1]:
            if i == 0 and j == 0:
                continue
            new_y = (y + j) % height
            new_x = (x + i) % length
            count += grid[new_y][new_x]

    return count



def compute_next_generation(grid):
    """
    Oblicza następną generację komórek zgodnie z regułami Gry w Życie.
    Zwraca: nową tablicę 2D z kolejną generacją komórek.
    """
    # Zaimplementować tę funkcję
    height = len(grid)
    length = len(grid[0])

    # length - x , height - y
    new_grid = [[0 for _ in range(length)] for _ in range(height)]
    for x in range(0, length):
        for y in range(0, height):
            count = count_neighbors(grid, x, y)
            if grid[y][x]:
                if count == 2 or count == 3:
                    new_grid[y][x] = 1
                else:
                    new_grid[y][x] = 0
            else:
                if count == 3:
                    new_grid[y][x] = 1
                else:
                    new_grid[y][x] = 0
    return new_grid



def draw_grid(stdscr,grid):
    if grid is None:
        stdscr.addstr("Error")
        stdscr.clear()
        return
    """
    Wyświetla siatkę komórek na ekranie terminala.
    """
    stdscr.clear()
    for y,row in enumerate(grid):
        for x,cell in enumerate(row):
            stdscr.addch(y,x,"#"if cell else" ")
    stdscr.refresh()


def game_loop(stdscr):
    """
    Główna pętla gry obsługująca wyświetlanie i aktualizację stanu planszy.
    Użytkownik może przechodzić do kolejnych generacji naciskając dowolny klawisz.
    Naciśnięcie 'q' kończy działanie programu.
    """
    # Ukrywa kursor, aby poprawić wygląd symulacji
    curses.curs_set(0)
    # Program czeka na wejście użytkownika
    stdscr.nodelay(False)
    stdscr.clear()
    # Pobranie rozmiaru terminala i dostosowanie planszy do jego wielkości
    height,width=stdscr.getmaxyx()
    # Uniknięcie problemów z krawędziami
    height,width=height-1,width-1
    grid=initialize_grid(height,width)
    while True:
        # Rysowanie aktualnej generacji planszy
        draw_grid(stdscr,grid)
        # Oczekiwanie na naciśnięcie klawisza
        key=stdscr.getch()
        if key==ord('q'):
            # Wyjście z programu po naciśnięciu 'q'
            break
        # Aktualizacja stanu gry zgodnie z zasadami
        grid=compute_next_generation(grid)
if __name__=="__main__":
    # Uruchomienie pętli gry w trybie curses
    curses.wrapper(game_loop)
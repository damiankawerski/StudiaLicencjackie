#include <iostream>

bool sprawdzWarunek(int macierz[][10], int n) {
    // Sprawdzenie warunku dla każdej kolumny, zaczynając od pierwszej do przedostatniej
    for (int kolumna = 0; kolumna < 9; ++kolumna) {
        int sumaAktualnejKolumny = 0;
        int sumaNastepnejKolumny = 0;

        // Sumowanie wartości z aktualnej i następnej kolumny
        for (int wiersz = 0; wiersz < n; ++wiersz) {
            sumaAktualnejKolumny += macierz[wiersz][kolumna];
            sumaNastepnejKolumny += macierz[wiersz][kolumna + 1];
        }

        // Sprawdzenie warunku
        if (sumaNastepnejKolumny <= sumaAktualnejKolumny) {
            return false;
        }
    }

    // Warunek został spełniony dla wszystkich kolumn
    return true;
}

int main() {
    const int n = 3;  // Przykładowa liczba wierszy
    int macierz[n][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                          {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
                          {94, 22, 23, 24, 25, 26, 27, 28, 29, 30}};

    if (sprawdzWarunek(macierz, n)) {
        std::cout << "Warunek został spełniony." << std::endl;
    } else {
        std::cout << "Warunek nie został spełniony." << std::endl;
    }

    return 0;
}

#include <iostream>

void rysujTrojkat(int wysokosc) {
    for (int i = 1; i <= wysokosc; ++i) {
        // Wypisz spacje przed znakami trójkąta
        for (int j = 0; j < wysokosc - i ; ++j) {
            std::cout << " ";
        }

        // Wypisz znaki trójkąta
        for (int j = 0; j < 2 * i - 1; ++j) {
            std::cout << "*";
        }

        // Przejdź do nowej linii po zakończeniu wiersza
        std::cout << std::endl;
    }
}

int main() {
    int wysokosc;

    // Pobierz od użytkownika wysokość trójkąta
    std::cout << "Podaj wysokosc trójkąta: ";
    std::cin >> wysokosc;

    // Wywołaj funkcję rysującą trójkąt
    rysujTrojkat(wysokosc);

    return 0;
}

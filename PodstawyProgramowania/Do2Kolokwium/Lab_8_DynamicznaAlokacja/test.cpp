#include <iostream>
#include <cstdlib>
#include <ctime>

void sortujTablice(int* tablica, int rozmiar) {
    for (int i = 0; i < rozmiar - 1; ++i) {
        for (int j = 0; j < rozmiar - i - 1; ++j) {
            if (tablica[j] > tablica[j + 1]) {
                int temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, m;
    std::cout << "Podaj liczbe elementow tablicy (n): ";
    std::cin >> n;

    std::cout << "Podaj liczbe m: ";
    std::cin >> m;

    int* tablica = new int[n];
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < n; ++i) {
        tablica[i] = std::rand() % 101 - 50;
    }

    sortujTablice(tablica, n);

    int iloscPar = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (tablica[i] + tablica[j] == m) {
                std::cout << "Para: (" << tablica[i] << ", " << tablica[j] << ")\n";
                iloscPar++;

                // Oznacz parę jako przetworzoną, aby uniknąć powtórek
                tablica[j] = m + 1;
                break; // Przerwij pętlę wewnętrzną
            }
        }
    }

    std::cout << "Ilosc par o sumie " << m << ": " << iloscPar << std::endl;

    delete[] tablica;
}


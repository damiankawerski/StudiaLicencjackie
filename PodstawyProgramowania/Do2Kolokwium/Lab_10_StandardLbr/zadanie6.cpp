#include <iostream>
#include <cstring>
#include <algorithm>

// Funkcja porównująca dla std::sort
bool porownajNapisyStdSort(const char* a, const char* b) {
    return std::strcmp(a, b) < 0;
}

int main() {
    // Tablica napisów
    const char* napisy[] = {"Orange", "Apple", "Banana", "Grape", "Pineapple"};

    // Rozmiar tablicy
    const size_t rozmiar = sizeof(napisy) / sizeof(napisy[0]);

   

    // Użycie std::sort
    std::sort(napisy, napisy + rozmiar, porownajNapisyStdSort);

    // Wyświetlenie wyniku std::sort
    std::cout << "\nPosortowane za pomocą std::sort:\n";
    for (size_t i = 0; i < rozmiar; ++i) {
        std::cout << napisy[i] << "\n";
    }

    return 0;
}

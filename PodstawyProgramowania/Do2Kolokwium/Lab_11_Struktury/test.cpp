#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funkcja porównująca dla qsort
int compareStrings(const void *a, const void *b) {
    const char *strA = *(const char **)a;
    const char *strB = *(const char **)b;

    int lenA = strlen(strA);
    int lenB = strlen(strB);

    int i = 0;
    while (i < lenA && i < lenB) {
        if (strA[lenA - 1 - i] < strB[lenB - 1 - i]) {
            return -1; // strA mniejsze od strB
        } else if (strA[lenA - 1 - i] > strB[lenB - 1 - i]) {
            return 1;  // strA większe od strB
        }
        i++;
    }

    // Jeżeli dotarliśmy do tego miejsca, oznacza to, że napisy są równe
    return 0;
}

int main() {
    // Przykładowa tablica napisów do posortowania
    const char *strings[] = {"abc", "xyz", "cba", "wxyz", "def"};

    // Określenie liczby elementów w tablicy
    size_t numStrings = sizeof(strings) / sizeof(strings[0]);

    // Sortowanie napisów przy użyciu qsort i funkcji porównującej
    qsort(strings, numStrings, sizeof(strings[0]), compareStrings);

    // Wyświetlenie posortowanych napisów
    for (size_t i = 0; i < numStrings; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}

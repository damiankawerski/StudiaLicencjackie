#include <cstdio>
#include <cstring>

void zamienSlowo(const char* sciezka, const char* nowyNapis) {
    FILE* plik = fopen(sciezka, "r");
    if (plik == nullptr) {
        perror("Błąd otwarcia pliku");
        return;
    }

    const int rozmiarBufora = 512;
    char bufor[rozmiarBufora];
    char wynik[rozmiarBufora * 2]; // Bufor dla zmodyfikowanego tekstu, rozmiarBufora * 2 dla bezpieczeństwa

    wynik[0] = '\0'; // Inicjalizacja wyniku jako pustego napisu

    while (fgets(bufor, rozmiarBufora, plik) != nullptr) {
        char* pozycja = strstr(bufor, "*****");
        while (pozycja != nullptr) {
            strncat(wynik, bufor, pozycja - bufor); // Dodaj fragment przed gwiazdkami
            strncat(wynik, nowyNapis, rozmiarBufora); // Dodaj nowy napis
            pozycja += 5; // Przesuń wskaźnik za gwiazdki
            bufor[0] = '\0'; // Usuń poprzednią treść z bufora
            strncat(bufor, pozycja, rozmiarBufora - 1); // Dodaj resztę bufora po gwiazdkach
            pozycja = strstr(bufor, "*****"); // Szukaj dalej
        }

        strncat(wynik, bufor, rozmiarBufora * 2); // Dodaj resztę linii
    }

    fclose(plik);

    plik = fopen(sciezka, "w");
    if (plik == nullptr) {
        perror("Błąd otwarcia pliku do zapisu");
        return;
    }

    fputs(wynik, plik); // Zapisz zmodyfikowaną zawartość do pliku
    fclose(plik);
}

int main() {
    const char* sciezka = "zadanie10.txt"; // Zastąp odpowiednią ścieżką
    char nowyNapis[512]; // Maksymalna długość nowego napisu
    printf("Podaj dowolnie dlugi napis: ");
    scanf("%511[^\n]", nowyNapis);

    zamienSlowo(sciezka, nowyNapis);

    return 0;
}

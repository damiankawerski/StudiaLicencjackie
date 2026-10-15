#include <iostream>
#include <cstring>

void zamienGwiazdki(char* tekst, const char* zamiana) {
    const char* gwiazdki = "*****";
    char* ptr = strstr(tekst, gwiazdki);

    while (ptr != nullptr) {
        // Znaleziono sekwencję "*****", zamień ją na podany napis
        size_t dlugoscZamiany = strlen(zamiana);
        size_t dlugoscGwiazdek = strlen(gwiazdki);

        if (dlugoscZamiany > dlugoscGwiazdek) {
            // Zamiana na dłuższy tekst, przesuń resztę tekstu w prawo
            memmove(ptr + dlugoscZamiany, ptr + dlugoscGwiazdek, strlen(ptr + dlugoscGwiazdek) + 1);
            strncpy(ptr, zamiana, dlugoscZamiany);
            ptr += dlugoscZamiany;
        } else if (dlugoscZamiany < dlugoscGwiazdek) {
            // Zamiana na krótszy tekst, przesuń resztę tekstu w lewo
            strncpy(ptr, zamiana, dlugoscZamiany);
            memmove(ptr + dlugoscZamiany, ptr + dlugoscGwiazdek, strlen(ptr + dlugoscGwiazdek) + 1);
            ptr += dlugoscZamiany;
        } else {
            // Zamiana na tekst o tej samej długości
            strncpy(ptr, zamiana, dlugoscZamiany);
            ptr += dlugoscZamiany;
        }

        // Spróbuj znaleźć kolejne wystąpienie "*****"
        ptr = strstr(ptr, gwiazdki);
    }
}

int main() {
    char tekst[] = "Autobus jest ***** i jedzie z *****";
    const char* zamiana = "czerwony";

    std::cout << "Przed zamianą: " << tekst << std::endl;

    zamienGwiazdki(tekst, zamiana);

    std::cout << "Po zamianie: " << tekst << std::endl;

    return 0;
}
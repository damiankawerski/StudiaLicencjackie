#include <iostream>

using namespace std;

int binarna_na_dziesietna(const char napis_binarny[]) {
    int wynik = 0;

    // Przechodzimy przez każdy znak liczby binarnej, zaczynając od najbardziej znaczącego
    for (int i = 0; napis_binarny[i] != '\0'; ++i) {
        // Mnożymy obecny wynik przez 2 i dodajemy wartość obecnego bitu
        wynik = (wynik << 1) + (napis_binarny[i] - '0');
    }

    return wynik;
}

int main() {
    const char napis_binarny[] = "1101";
    int wynik = binarna_na_dziesietna(napis_binarny);

    cout << "Wartość dziesiętna: " << wynik << endl;

    return 0;
}

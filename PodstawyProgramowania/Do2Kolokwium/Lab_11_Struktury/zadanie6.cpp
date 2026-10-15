#include <iostream>
#include <cstring>
using namespace std;


int main() {
    
    const char* inputString = "ala;ma kota;i;dwa psy";
    char *inputCopy = new char[strlen(inputString) + 1];
    strcpy(inputCopy, inputString);

    char delimiter = ';';
    
    // Użycie funkcji strtok do podzielenia napisu
    char* token = std::strtok(inputCopy, &delimiter);

    // Tablica char* do przechowywania tokenów
    const int maxTokens = 100;
    char* tokens[maxTokens];

    // Indeks do przechodzenia przez tablicę tokenów
    int tokenIndex = 0;

    // Pobieranie kolejnych tokenów
    while (token != nullptr && tokenIndex < maxTokens) {
        // Przypisanie tokenu do tablicy
        tokens[tokenIndex++] = token;

        // Pobranie kolejnego tokenu
        token = std::strtok(nullptr, &delimiter);
    }

    // Wyświetlenie tokenów na ekranie
    std::cout << "Podzielone tokeny:\n";
    for (int i = 0; i < tokenIndex; ++i) {
        std::cout << tokens[i] << std::endl;
    }
    delete[] inputCopy;

    return 0;
}

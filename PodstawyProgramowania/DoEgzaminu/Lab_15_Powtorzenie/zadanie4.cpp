#include <iostream>
#include <fstream>
#include <ctime>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Użycie: " << argv[0] << " <nazwa_pliku>" << std::endl;
        return 1;
    }

    const char *nazwaPliku = argv[1];
    
    // Otwarcie pliku do dopisania
    std::ofstream plik(nazwaPliku, std::ios::app);

    if (!plik) {
        std::cerr << "Nie można otworzyć pliku do zapisu." << std::endl;
        return 1;
    }

    // Pobranie aktualnej daty i czasu
    std::time_t czas = std::time(0);
    std::tm *lokalnyCzas = std::localtime(&czas);
    char dataCzas[20];
    std::strftime(dataCzas, sizeof(dataCzas), "%d-%m-%Y %H:%M:%S", lokalnyCzas);

    // Dopisanie daty i czasu na koniec pliku
    plik << std::endl << dataCzas << std::endl;

    std::cout << "Data i czas zostały dodane do pliku." << std::endl;

    return 0;
}

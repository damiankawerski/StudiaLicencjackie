#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Użycie: " << argv[0] << " <nazwa_pliku>" << endl;
        return 1;
    }

    const char* filename = argv[1];
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Nie można otworzyć pliku " << filename << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        // Konwersja daty/czasu ze stringa na strukturę tm
        tm tm_date;
        strptime(line.c_str(), "%d-%m-%Y %H:%M:%S", &tm_date);

        // Dodanie 15 dni i 37 godzin
        tm_date.tm_mday += 15;
        tm_date.tm_hour += 37;

        // Konwersja z powrotem do stringa
        char output[20];
        strftime(output, sizeof(output), "%d-%m-%Y %H:%M:%S", &tm_date);
        cout << "Oryginalna data/czas: " << line << ", Nowa data/czas: " << output << endl;
    }

    file.close();
    return 0;
}

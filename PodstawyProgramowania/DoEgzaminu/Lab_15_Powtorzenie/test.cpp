#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class City {
private:
    string name;
    unsigned int population;
    double width;
    double length;

public:
    City() : name("name"), population(0), width(0), length(0) {}

    friend ostream& operator<<(ostream& os, const City& obj) {
        os << obj.name << "      " << obj.population << "      " << obj.width << "      " << obj.length;
        return os;
    }

    City(string name, unsigned int pop, double wid, double len) : name(name), population(pop), width(wid), length(len) {}

    City(const City& other) {
        name = other.name;
        population = other.population;
        width = other.width;
        length = other.length;
    }

    City& operator=(const City& other) {
        if (this != &other) {
            name = other.name;
            population = other.population;
            width = other.width;
            length = other.length;
        }
        return *this;
    }

    void readFromCsv(const char* direction, City* arr, int& size) {
        ifstream file(direction);
        if (!file.is_open()) {
            cerr << "Error opening file: " << direction << endl;
            return;
        }

        string line;
        getline(file, line);  // Skip the header line

        while (getline(file, line)) {
            istringstream strStream(line);
            strStream >> arr[size].name;
            strStream >> arr[size].population;
            strStream >> arr[size].width;
            strStream >> arr[size].length;
            size++;
        }

        file.close();
    }
};

int main() {
    const char* dir = "cities.csv";
    int amount = 0;
    int max_cities = 250;
    City cities[max_cities];
    cities[0].readFromCsv(dir, cities, amount);

    for (int i = 0; i < amount; i++) {
        cout << cities[i] << endl;
    }

    return 0;
}

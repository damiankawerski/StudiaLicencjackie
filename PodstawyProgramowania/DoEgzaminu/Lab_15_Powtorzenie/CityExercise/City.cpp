#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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
        os << "City: " << setw(15) << left << obj.name << "Population: " << setw(9) << obj.population << "Position: (" << fixed << setprecision(6) << obj.width << " : " << obj.length << ")";   
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
        if(this != &other) {
            name = other.name;
            population = other.population;
            width = other.width;
            length = other.length;
        }
        return *this;
    }

     void readFromCsv(const char* direction, City* arr, int &size, int max_size) {
        ifstream file(direction);
        if(!file.is_open()) {
            return;
        }
        string line;
        getline(file, line);
        while(getline(file, line) && size < max_size) {
            if(line[0] == '#') continue;
            stringstream strStream(line);
            getline(strStream, arr[size].name, ',');
            strStream >> arr[size].population;
            strStream.ignore();
            strStream >> arr[size].width;
            strStream.ignore();
            strStream >> arr[size].length;
            size++;
        }
        file.close();
    }

    void saveToCsv(const char* direction, City* arr, int size) {
        ofstream file(direction);
        if(!file.is_open()) {
            return;
        }
        for(int i = 0 ; i < size ; i++) {
            stringstream strStream;
            strStream << arr[i].name << "," << arr[i].population << "," << arr[i].width << "," << arr[i].length << endl;
            file << strStream.str();
        }
        file.close();
    }

    void readFromBin(const char* dir, City* arr, int& size, int max_size) {
        ifstream file(dir, ios::binary);
        if(!file.is_open()) {
            return;
        }
        string line;
        getline(file, line);
        while(getline(file, line) && size < max_size) {
            if(line[0] == '#') continue;
            stringstream strStream(line);
            getline(strStream, arr[size].name, ',');
            strStream >> arr[size].population;
            strStream.ignore();
            strStream >> arr[size].width;
            strStream.ignore();
            strStream >> arr[size].length;
            size++;
        }
        file.close();
    }

    void saveToBin(const char* direction, City* arr, int size) {
        ofstream file(direction, ios::binary);
        if(!file.is_open()) {
            return;
        }
        for(int i = 0 ; i < size ; i++) {
            stringstream strStream;
            strStream << arr[i].name << "," << arr[i].population << "," << arr[i].width << "," << arr[i].length << endl;
            file << strStream.str();
        }
        file.close();
    }

    void clearFile(const char* dir) {
        ofstream file(dir, ios::trunc);
        file.close();
    }
};

void showCities (City* arr, int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    const char* dirCSV = "cities.csv";
    const char* copyCSV = "kopia.csv";
    const char* dirBIN = "cities.bin";
    const char* copyBIN = "kopia.bin";
    int amount = 0;
    int max_cities = 250;
    City cities[max_cities];
    cities->readFromCsv(dirCSV, cities, amount, max_cities);
    //showCities(cities, amount);
    //cities->saveToCsv(copyCSV, cities, amount);
    //cities->clearFile(copyCSV);
    cities->saveToBin(dirBIN, cities, amount);
    return 0;
}
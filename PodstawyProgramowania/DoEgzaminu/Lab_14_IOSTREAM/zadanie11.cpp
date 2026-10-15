#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct City {
    char name[50];
    unsigned int people;
    double x;
    double y;
};

const int MAX_CITIES = 100;

void load_csv_city(const char* plik, City *cities, int &amount_of_cities) {
    FILE* file = fopen(plik, "r");
    if(!file) {
        return;
    }

    amount_of_cities = 0;
    char line[250];

    fgets(line, sizeof(line), file);

    while(fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%49[^,],%u,%lf,%lf", cities[amount_of_cities].name, &cities[amount_of_cities].people, &cities[amount_of_cities].x, &cities[amount_of_cities].y);
        amount_of_cities++;
        if(amount_of_cities > MAX_CITIES) {
            return;
        }
    }
    fclose(file);
}

int main() {
    int size;
    City arr[MAX_CITIES];
    const char* sciezka = "cities.csv";
    load_csv_city(sciezka, arr, size);

    cout << "Nazwa miasta       Populacja       Długoćs X,      Dlugosc Y" << endl;
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i].name << "        " << arr[i].people << "         " << arr[i].x << "          " << arr[i].y << endl;
    }
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int count(char* plik) {
    int counter = 0;
    FILE* file = fopen(plik, "r");
    char x;
    while(fscanf(file, "%c", &x) != EOF) {
        counter++;
    }
    fclose(file);
    return counter;
}

void read_strings(char *plik, char *result, int size) {
    FILE* file = fopen(plik, "r");
    int index = 0;
    while(fscanf(file, "%c", result + index) != EOF) {
        index++;
    }
    result[size] = '\0';
    fclose(file);
}

int main() {
    char sciezka[30] = "zadanie8.txt";
    int size = count(sciezka);
    char *result = new char[size + 1];
    read_strings(sciezka, result, size);
    cout << result << endl;
    delete[] result;
    return 0;
}
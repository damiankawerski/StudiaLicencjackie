#include <iostream>
#include <cstdio>
#include <cstring>
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

void change_arr(char* input, int size, char* word) {
    char* token = strstr(input, "*****");
    for(int i = 0 ; i < 5; i++) {
        *(token + i) = word[i];
    }
}

void change_stars(char* plik, char* arr, int size) {
    FILE* file = fopen(plik, "w");
    fwrite(arr, sizeof(char), size, file);
    fclose(file);
}

int main() {
    char word[6] = "kota";
    char sciezka[30] = "zadanie9.txt";
    int size = count(sciezka);
    char *arr = new char[size];
    read_strings(sciezka, arr, size);
    change_arr(arr, size, word);
    change_stars(sciezka, arr, size);
    delete[] arr;
    return 0;
}
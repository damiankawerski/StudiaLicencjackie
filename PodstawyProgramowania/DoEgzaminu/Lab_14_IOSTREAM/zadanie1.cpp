#include <iostream>
#include <cstdio>
using namespace std;

void zad1(char* plik) {
    int minF, maxF;
    int min, max;
    minF = 0;
    maxF = 0;

    FILE* file = fopen(plik, "r");

    while(fscanf(file, "%d", &min) != EOF){
        if(min < minF) minF = min;
    }

    rewind(file);

    while(fscanf(file, "%d", &max) != EOF){
        if(max > maxF) maxF = max;
    }

    fclose(file);

    cout << minF << endl;
    cout << maxF << endl;
}

int main() {
    char plik[30] = "zadanie1.txt";
    zad1(plik);
    return 0;
}
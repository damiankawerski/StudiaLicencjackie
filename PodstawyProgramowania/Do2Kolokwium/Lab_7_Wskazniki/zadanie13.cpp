#include <iostream>
using namespace std;

int strLength(char* start) {
    if(*start == '\0') return 0;
    return strLength(start + 1) + 1;
}

void strCopy(char* start, char* copy, int size) {
    for(int i = 0 ; i < size ; i++) {
        *copy = *start;
        copy++;
        start++;
    }
}

int main() {
    char napis[100] = "Ala ma kota";
    char kopia[100];
    strCopy(napis, kopia, strLength(napis) + 1);
    cout << kopia << endl;
    return 0;
}
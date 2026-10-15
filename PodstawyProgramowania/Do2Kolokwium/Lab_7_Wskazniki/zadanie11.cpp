#include <iostream>
using namespace std;

int lengthLoop(char* start) {
    int counter = 0;
    while(*start != '\0') {
        counter++;
        start++;
    }
    return counter;
}

int lengthRekur(char* start) {
    if(*start == '\0') return 0;
    return lengthRekur(start + 1) + 1;
}

int main() {
    char napis[100] = "Ala ma kota";
    cout << lengthLoop(napis) << endl;
    cout << lengthRekur(napis) << endl;
    return 0;
}
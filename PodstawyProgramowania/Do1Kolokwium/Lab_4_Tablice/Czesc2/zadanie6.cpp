#include <iostream>
using namespace std;
int main() {
    char napis[20] = "alamakota";
    char podciag[20] = "mak";

    int napisL = 0;
    int podciagL = 0;

    while(napis[napisL] != '\0') napisL++;
    while(podciag[podciagL] != '\0') podciagL++;
    


    for(int i = 0 ; i <= napisL - podciagL ; i++) {
        int j = 0;
        while(j < podciagL && napis[i + j] == podciag[j]) j++;

        if (j == podciagL) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int strSize(char napis[]) {
    int counter = 0;
    while(napis[counter] != '\0') {
        counter++;
    }
    return counter;
}

int fun(char napis[]) {
    int number = 0;
    int counter = 0;
    while(counter < strSize(napis)) {
        number += (napis[counter] - '0') * pow(10, strSize(napis) - counter - 1);
        counter++;
    }
    return number;
}

int main() {
    char napis[] = "1234";
    cout << fun(napis) << endl;
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int strLength(char str[]) {
    int counter = 0;
    while(str[counter] != '\0') {
        counter++;
    }
    return counter;
}

bool isNoNumber(char str[]) {
    for(int i = 0 ; i < strLength(str) - 1 ; i++) {
        if(str[i] > '9' || str[i] < '0')  return true;
    }
    return false;
}

int stringToInt(char str[]) {
    int number = 0;
    if(isNoNumber(str)) return -1;
    else {
        for(int i = 0 ; i < strLength(str) ; i++) {
            number = number + (str[i] - '0') * pow(10, i);
        }
    }
    return number; 
}

int main() {
    char str[100];
    cin.getline(str, 100);
    cout << stringToInt(str) << endl;
    return 0;
}
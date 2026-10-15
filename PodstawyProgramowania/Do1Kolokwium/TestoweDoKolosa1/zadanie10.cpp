#include <iostream>
using namespace std;

bool compareLetters(char str[], int indexI, int indexJ) {
    int bigToSmall = 'a' - 'A';
    if(str[indexI] == str[indexJ] || str[indexI] == str[indexJ] + bigToSmall || str[indexI] == str[indexJ] - bigToSmall ) return true;
    return false;
}



void countLetters(char str[], int occ[], int length) {
    int count;
    for(int i = 0 ; i < length ; i++) {
        count = 0;
        for(int j = 0 ; j < length ; j++) {
            if(compareLetters(str, i, j)) {
                count++;
            }
        }
        occ[i] = count;
    }
}

void showOcc(int occ[], int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << occ[i] << "  ";
    }
}

int main() {
    char str[] = "Ala ma kota";
    int strSize = sizeof(str) - 1;
    int occ[strSize];
    countLetters(str, occ, strSize);
    showOcc(occ, strSize);
    return 0;
}
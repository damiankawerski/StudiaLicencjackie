#include <iostream>
using namespace std;

int main() {
    char napis[100];
    cin.getline(napis, 100);
    int counter = 0;
    while(napis[counter] != '\0') {
        counter++;
    }
    char napisR[100];
    int size = counter;
    for(int i = 0 ; i < size + 1 ; i++) {
        counter--;
        napisR[i] = napis[counter];
    }
    napisR[size] = '\0';
    for(int i = 0 ; i < size ; i++) {
        napis[i] = napisR[i];
    }
    
    cout << napis << endl;
    return 0;
}

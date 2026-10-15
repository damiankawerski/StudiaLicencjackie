#include <iostream> 
using namespace std;

int strLength(char str[]) { 
    int counter = 0;
    while(str[counter] != '\0') {
        counter ++;
    }
    return counter;
}

int fun(char str[]) {
    int counter = 1;
    for(int i = 0 ; i < strLength(str) ; i++) {
        if(str[i] == ' ') {
            counter++;
        }
    }
    return counter;
}

int main() {
    char str[100] = "ala ma kota";
    cout << fun(str) << endl;
    return 0;
}
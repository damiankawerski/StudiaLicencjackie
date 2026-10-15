#include <iostream>
using namespace std;

void intToBin(unsigned int n) {
    int temp[32];
    int counter = 0;
    int binArr[32];

    while(n > 0) {
        temp[counter] = n % 2;
        n = n/2;
        counter++;
    }

    int index = 0;

    while(counter > 0) {
        counter--;
        binArr[index] = temp[counter];
        index++;
    }

    while(counter < index) {
        cout << binArr[counter] << " ";
        counter++;
    }
}

int main() {
    unsigned int n;
    cin >> n;
    intToBin(n);
    return 0;
}
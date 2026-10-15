#include <iostream>
using namespace std;

int binLength(char bin[]) {
    int l = 0;
    while (bin[l] != '\0') {
        l++;
    }
    return l;
}

int binToDec(char bin[], int i = 0) {
    if(i == binLength(bin)) return 0;

    int result = binToDec(bin, i + 1);

    int bitValue = bin[i] - '0';

    result += bitValue * (1 << (binLength(bin) - i - 1));

    return result;
}

int main() {
    char binNumber[32] = "10010011";
    cout << binToDec(binNumber) << endl;
}
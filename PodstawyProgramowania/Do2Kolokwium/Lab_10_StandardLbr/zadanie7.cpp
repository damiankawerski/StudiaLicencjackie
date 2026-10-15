#include <iostream>
using namespace std;

int main() {
    char input[11];
    cin.getline(input, 11);
    int number = atoi(input);
    number += 10;
    cout << number;
    return 0;
}
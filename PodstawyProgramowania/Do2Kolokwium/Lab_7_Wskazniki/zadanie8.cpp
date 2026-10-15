#include <iostream>
using namespace std;

int fun(int* a, int* b) {
    return *a < *b ? *a : *b;
}

int main() {
    int a, b;
    a = 11;
    b = 10;
    cout << fun(&a, &b) << endl;
    return 0;
}
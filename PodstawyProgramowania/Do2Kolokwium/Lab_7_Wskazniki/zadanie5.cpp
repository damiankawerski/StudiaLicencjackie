#include <iostream>
using namespace std;

void swapTest(int &a, int *b) {
    int temp = a;
    a = *b;
    *b = temp;
}

int main() {
    int  a = 5;
    int b = 10;
    swapTest(a, &b);
    cout << a << " : " << b << endl;
    return 0;
}
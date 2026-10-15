#include <iostream>
using namespace std;

void fun(int *x, int *y, int &z) {
    z = *x + *y;
}

int main() {
    int x, y, z;
    x = 4;
    y = 5;
    fun(&x, &y, z);
    cout << z << endl;
    return 0;
}
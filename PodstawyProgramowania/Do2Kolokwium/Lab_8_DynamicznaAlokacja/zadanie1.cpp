#include <iostream>
using namespace std;

int* fun(int* a, int* b) {
    if(*a > *b) return b;
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << *fun(&a, &b) << endl;
    return 0;
}
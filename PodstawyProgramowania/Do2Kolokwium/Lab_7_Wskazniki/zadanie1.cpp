#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int *wsk;
    cout << *wsk << endl << wsk << endl;
    cout << n << endl << &n << endl;
    wsk = &n;
    cout << *wsk << endl << wsk << endl;
    return 0;
}
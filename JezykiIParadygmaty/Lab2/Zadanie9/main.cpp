#include <iostream>
using namespace std;

int x = 2;
int y = 1;

void f() {
    x = x + 1;
    y = y + 2;
    cout << x << " " << y << endl;
}

void g() {
    int x = 1;
    x = x + 2;
    y = y + 1;
    cout << x << " " << y << endl;
    f();
}

int main() {
    g();
    f();
}
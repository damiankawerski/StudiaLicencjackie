#include <iostream>
using namespace std;

int fun(unsigned int n) {
    if(n == 0 || n == 1) return 1;
    if(n % 2 == 0) return fun(n-1) + n;
    if(n % 2 != 0) return fun(n-1) * n;
    return 0;
}

int main() {
    int n;
    cin >> n;
    cout << fun(n) << endl;
    return 0;
}
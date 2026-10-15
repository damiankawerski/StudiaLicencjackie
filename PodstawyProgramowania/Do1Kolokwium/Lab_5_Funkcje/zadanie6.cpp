#include <iostream>
#include <cmath>
using namespace std;
int fun_wyk(int n) {
    return pow(2, n);
}
int main() {
    int n;
    cin >> n;
    cout << fun_wyk(n) << endl;
}

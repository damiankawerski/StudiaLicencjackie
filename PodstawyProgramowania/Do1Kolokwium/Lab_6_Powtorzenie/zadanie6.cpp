#include <iostream>
using namespace std;

int ifPower2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;
    cin >> n;
    cout << ifPower2(n) << endl;
    return 0;
}
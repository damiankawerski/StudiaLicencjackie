#include <iostream>
using namespace std;

int bitReading(unsigned int x, int n) {
    int mask = (1 << n);
    return ((x & mask) != 0);
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << bitReading(x, n) << endl;
    return 0;
}
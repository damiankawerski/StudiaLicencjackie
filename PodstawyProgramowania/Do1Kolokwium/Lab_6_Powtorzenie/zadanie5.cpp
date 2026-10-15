#include <iostream>
using namespace std;

int bitReading(unsigned int x) {
    return ((x & 1) == 1);
}

int main() {
    int x;
    cin >> x;
    cout << bitReading(x) << endl;
    return 0;
}
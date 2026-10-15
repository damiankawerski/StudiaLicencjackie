#include <iostream>
using namespace std;

int seriesFunction(unsigned int n) {
    if(n == 0 || n == 1) return 1;
    return seriesFunction(n-1) + 2 * seriesFunction(n - 2) + 3;
}

int main() {
    unsigned int n;
    cin >> n;
    cout << seriesFunction(n) << endl;
    return 0;
}
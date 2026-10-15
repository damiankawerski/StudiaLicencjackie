#include <iostream>
#include <cmath>
using namespace std;

int max_pow2(int k) {
    int result;
    for(int n = 0 ; pow(2, n) < k ; n++) {
        result = pow(2, n);
    }
    return result;
}

int main() {
    int k;
    cin >> k;
    cout << max_pow2(k) << endl;
    return 0;
}
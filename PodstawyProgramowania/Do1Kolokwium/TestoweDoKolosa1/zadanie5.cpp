#include <iostream>
#include <cmath>
using namespace std;

float funPlus(float arr[], unsigned int n) {
    if(n == 0) return 0;
    return pow((-1), n) * arr[n - 1] + funPlus(arr, n - 1);
}

void fun(float arr[], unsigned int n) {
    for(int i = 1 ; i <= n ; i++) {
        cout << funPlus(arr, i) << endl;
    }
}

int main() {
    unsigned int n;
    cin >> n;
    if(n >= 20) return 0;
    float arr[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    fun(arr, n);
    return 0;
}
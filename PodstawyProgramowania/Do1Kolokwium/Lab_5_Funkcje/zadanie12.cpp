#include <iostream>
using namespace std;

int fibonacci_loop(int n) {
    if(n == 1 || n == 2) return 1;
    int n_current;
    int n_minus1 = 1;
    int n_minus2 = 1;
    for(int i = 3 ; i <= n ; i++) {
        n_current = n_minus1 + n_minus2;
        n_minus2 = n_minus1;
        n_minus1 = n_current;
    }
    return n_current;
}


int fibonacci_rekur(int n) {
    if(n == 1 || n == 2) return 1;
    return fibonacci_rekur(n-1) + fibonacci_rekur(n-2);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci_loop(n) << endl;
    cout << fibonacci_rekur(n) << endl;
    return 0;
}
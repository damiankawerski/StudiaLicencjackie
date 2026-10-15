#include <iostream>
using namespace std;

unsigned int fun_rekur(unsigned int n) {
    if(n < 2) return 1;
    if(n >= 2 && n < 10) return 2 * fun_rekur(n - 1);
    if(n >=10) return 3 * fun_rekur(n - 1) - fun_rekur(n - 3);
    return 0;
}

int main() {
    unsigned int n;
    cin >> n;
    unsigned int result = fun_rekur(n);
    cout << result << endl;
    return 0;
}
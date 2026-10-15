#include <iostream>
using namespace std;

int silnia_petla(int n) {
    if(n == 0) return 1;
    int silnia = 1;
    while(n != 0) {
        silnia *= n;
        n--;
    }
    return silnia;
}


int silnia_rekur(int n) {
    if(n == 0 || n == 1) return 1;
    return n * silnia_rekur(n-1);
}



int main() {
    int n;
    cin >> n;
    cout << silnia_petla(n) << endl;
    cout << silnia_rekur(n) << endl;
    return 0;
}
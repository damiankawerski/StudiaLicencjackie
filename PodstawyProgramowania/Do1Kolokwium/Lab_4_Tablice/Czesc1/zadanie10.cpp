#include <iostream>
using namespace std;
int main() {
    const int n = 6;
    int arr[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    int suma = 0;
    for(int i = 0 ; i < n ; i++) {
        suma += arr[i];
    }
    cout << suma/n << endl;
    return 0;
} //XDDD
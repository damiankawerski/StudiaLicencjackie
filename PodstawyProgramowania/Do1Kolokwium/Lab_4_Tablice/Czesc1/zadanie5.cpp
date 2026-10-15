#include <iostream>
using namespace std;
int main() {
    const int n = 5;
    const int m = 4;
    int arr1[n];
    int arr2[m];
    int arr3[m+n];
    for(int i = 0 ; i < n ; i++) {
        cin >> arr1[i];
    }
    for(int i = 0 ; i < m ; i++) {
        cin >> arr2[i];
    }
    for(int i = 0 ; i < n ; i++) {
        arr3[i] = arr1[i];
    }
    for(int i = n , j = 0 ; i < (n+m)  ; j++, i++) {
        arr3[i] = arr2[j];
    }
    for(int i = 0 ; i < (n+m) ; i++) {
        cout << arr3[i] << endl;
    }
    
    
    return 0;
}
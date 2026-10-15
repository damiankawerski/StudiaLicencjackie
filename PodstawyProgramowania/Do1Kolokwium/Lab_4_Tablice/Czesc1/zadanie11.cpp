#include <iostream>
using namespace std;
int main() {
    const int n = 6;
    int arr[n];
    int temp[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    for(int i = 0 ; i < n ; i++) {
        if((i+1) != n) {
            temp[i + 1] = arr[i];
        }
        else {
            temp[0] = arr[n-1];
        }
       
    }
    for(int i = 0 ; i < n ; i++) {
        arr[i] = temp[i];
    }
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
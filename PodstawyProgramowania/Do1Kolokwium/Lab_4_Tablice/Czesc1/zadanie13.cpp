#include <iostream>
using namespace std;
int main() {
    const int n = 6;
    int arr[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                
            }
        }
    }
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
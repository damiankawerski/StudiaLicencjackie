#include <iostream>
using namespace std;
int main() {
    const int n = 6;
    int arr[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    int temp[n];
    int start = 0;
    int end = (n-1);
    for(int i = 0 ; i < n ; i++) {
        if(arr[i]%2 == 0) {
            temp[start] = arr[i];
            start++;
        }
        else {
            temp[end] = arr[i];
            end--;
        }
    }
    for(int i = 0 ; i<n ; i++) {
        arr[i] = temp[i];
    }
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
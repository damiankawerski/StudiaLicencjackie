#include <iostream>
using namespace std;

void arr_copy(int arr[], int arrcpy[], int size) {
    for(int i = 0 ; i < size ; i++) {
        arrcpy[i] = arr[i];
    }
}

int main() {
    int size;
    cin >> size;
    int arr[size];
    int arrcpy[size];
    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }
    arr_copy(arr, arrcpy, size);

    for(int i = 0 ; i < size ; i++) {
        cout << arrcpy[i];
    }
    return 0;
}
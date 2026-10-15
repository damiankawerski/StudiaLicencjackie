#include <iostream>
using namespace std;

void arr_sort(double arr[], int size) {
    double temp[size];
    int start = 0;
    int end = (size-1);

    for(int i = 0 ; i < size ; i++) {
        if(arr[i] == 0) {
            temp[end] = arr[i];
            end--;
        }
        else {
            temp[start] = arr[i];
            start++;
        }
    }
    for(int i = 0 ; i < size ; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int size;
    cin >> size;
    double arr[size];
    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }
    arr_sort(arr, size);
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
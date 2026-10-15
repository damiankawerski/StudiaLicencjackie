#include <iostream>
using namespace std;

void sort(int arr[], int size) {
    for(int i = 0 ; i < size ; i++) {
        for(int j = 0 ; j < size ; j ++) {
            if(arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int second_max(int arr[], int size) {
    if(size <= 2) return -1;
    sort(arr, size);
    return arr[size - 2];
}


int main() {
    int size;
    cin >> size;
    int arr[size];
    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }
    cout << second_max(arr, size) << endl;
    return 0;
}
  

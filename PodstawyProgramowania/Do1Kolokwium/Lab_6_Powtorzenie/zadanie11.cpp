#include <iostream>
using namespace std;

bool ifPalindrom(float arr[], int size) {
    int counter = 0;
    int end = size - 1;
    for(int i = 0 ; i < size/2 ; i++ ) {
        if(arr[i] == arr[end]) {
            counter++;
            end--;
        }
    }
    if(counter == size/2) return true;
    return false;
}

int main() {
    int size = 10;
    float arr[size];
    for(int i = 0 ; i < size ; i++ ) {
        cin >> arr[i];
    }
    cout << ifPalindrom(arr, size) << endl;
    return 0;
}
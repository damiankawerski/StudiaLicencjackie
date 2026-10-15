#include <iostream>
#include <algorithm>
using namespace std;

bool compareSort(int a, int b) {
    return a < b;
}



int fun(int *arr, int size, int number) {
    sort(arr, arr + size, compareSort);
    for(int i = 0 ; i < size ; i++) {
        if(arr[i] == number) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size = 12;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int number;
    cin >> number;
    cout << fun(arr, size, number) << endl;
    return 0;
}
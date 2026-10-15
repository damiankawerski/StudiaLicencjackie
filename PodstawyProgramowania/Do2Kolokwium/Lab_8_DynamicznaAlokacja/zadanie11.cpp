#include <iostream>
#include <algorithm>
using namespace std;

void show_arr(int n) {
    cout << n << " ";
}

void fill_arr(int *arr, int size) {
    for(int i = 0 ; i < size ; i ++) {
        arr[i] = i;
    }
}

void change_size(int *&arr, int size, int new_size) {
    int *kopia = new int[new_size];
    copy(arr, arr + new_size, kopia);
    if(new_size > size) {
        fill(kopia + size, kopia + new_size, 0);
    }
    delete[] arr;
    arr = kopia;
}

int main() {
    int new_size;
    cin >> new_size;
    int size = 6;
    int *arr = new int[6];
    fill_arr(arr, size);
    change_size(arr, size, new_size);
    for_each(arr, arr + new_size, show_arr);
    delete[] arr;
    return 0;
}
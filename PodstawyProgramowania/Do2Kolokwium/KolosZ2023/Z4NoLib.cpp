#include <iostream>
#include <cstring>
using namespace std;

bool compare(char *arr1, char* arr2, size_t size, int index) {
    size_t cond = 0;
    for(size_t i = 0 ; i < size ; i++) {
        if(*(arr1 + index * size + i) == *(arr2 + index * size + i)) {
            cond++;
        }
    }
    if(cond == size) {
        return true;
    }
    return false;
}

void set_to_zero(char *arr1, char* arr2, size_t size, int index) {
    for(size_t i = 0 ; i < size ; i++) {
        //*(arr1 + index * size + i) &= 0;
        //*(arr2 + index * size + i) &= 0;
        memset(arr1 + index * size, 0, size);
        memset(arr2 + index * size, 0, size);

    }
}

void null_set(void *arr1, void* arr2, int n, size_t size) {
    for(int i = 0 ; i < n ; i++) {
        if(compare(static_cast<char*>(arr1), static_cast<char*>(arr2), size, i)) {
            set_to_zero(static_cast<char*>(arr1), static_cast<char*>(arr2), size, i);
        }
    }
}

void show_arr(float *arr, int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 4;
    float arr1[n] = {8.0, 9.3, 10.7, 11.5};
    float arr2[n] = {8.0, 3.9, 10.7, 4.3};
    size_t size = sizeof(arr1) / sizeof(arr1[0]);
    null_set(arr1, arr2, n, size);
    show_arr(arr1, n);
    show_arr(arr2, n);
    return 0;
}
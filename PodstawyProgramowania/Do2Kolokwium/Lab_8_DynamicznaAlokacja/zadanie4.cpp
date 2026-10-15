#include <iostream>
using namespace std;

int countSize(float arr[], int size, int min, int max) {
    int counter = 0;
    for(int i = 0 ; i < size ; i++) {
        if(arr[i] >= min && arr[i] < max) {
            counter ++;
        }
    }
    return counter;
}

void copyAndChangeArr(float arr[], float arr1[], int min, int max, int size) {
    int index = 0;
    for(int i = 0 ; i < size ; i++) {
        if(arr[i] >= min && arr1[i] < max) {
            arr1[index] = arr[i];
            index++;
        }
    }
}

float* fun(float arr[],  int size, float min, float max, int* n_out) {
    *n_out = countSize(arr, size, min, max);
    float* arr1 = new float[*n_out];
    copyAndChangeArr(arr, arr1, min, max, size);
    return arr1;
}

void showArr(float *arr, float* end) {
     while(arr  < end) {
        cout << *arr << " ";
        arr++;
    }
}  

int main() {
    float array[5] = {1, 2, 3, 4, 5};
    int n_out;
    float * array1 = fun(array, 5, 2, 5, &n_out);
    showArr(array1, array1 + n_out);
    delete[] array1;
    return 0;
}
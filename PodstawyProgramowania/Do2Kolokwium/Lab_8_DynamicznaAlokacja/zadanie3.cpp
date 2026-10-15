#include <iostream>
using namespace std;

void fillArrWithZero(float* arr, float* end) {
    while(arr < end) {
        *arr = 0.0;
         arr++;
    }
}

void fillArrWithOne(float* arr, float* end) {
    while(arr < end) {
        *arr = 1.0;
         arr++;
    }
}

void showArr(float *arr, float* end) {
     while(arr  < end) {
        cout << *arr << " ";
        arr++;
    }
}  



int main() {
    unsigned int n;
    cin >> n;
    float* arr = new float[n];
    fillArrWithZero(arr, arr + n);
    showArr(arr, arr + n);
    delete[] arr;
    arr = new float[10];
    fillArrWithOne(arr, arr + 10);
    cout << endl << endl;
    showArr(arr, arr + 10);
    delete[] arr;
    return 0;
}


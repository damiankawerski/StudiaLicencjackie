#include <iostream>
using namespace std;

void fun(float arr1[], int size1, int arr2[], int size2) {
    for(int i = 0 ; i < size2 ; i++) {
        if(arr2[i] > size1) cout << "NAN" << endl;
        else cout << arr1[arr2[i]] << endl;
    }
}

void fillArr(float* arr, float* end) {
    int number = 0;
    while(arr < end) {
        *arr = number;
         arr++;
         number++;
    }
}

int main() {
    float* arr1 = new float[10];
    int* arr2 = new int[5];
    fillArr(arr1, arr1 + 10);
    for(int i = 0 ; i < 5 ; i++) {
        cin >> arr2[i];
    }
    fun(arr1, 10, arr2, 5);
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

void swapComplex(float arr[], int index1, int index2) {
    //Zamien Re:
    float temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    //Zamien Im:
    temp = arr[index1 + 1];
    arr[index1 + 1] = arr[index2 + 1];
    arr[index2 + 1] = temp;
}

void sortComplex(float arr[], int size) {
    for(int i = 0 ; i < size  - 1 ; i++) {
        for(int j = 0 ; j < size - 1; j++) {
            float modulo1 = sqrt(pow(arr[2 * j], 2) + pow(arr[2 * j + 1], 2));
            float modulo2 = sqrt(pow(arr[2 * (j + 1)], 2) + pow(arr[2 * (j + 1) + 1], 2));
            if(modulo1 > modulo2) {
                swapComplex(arr, 2 * j, 2 * (j + 1));
            }
        }
    }
}

void fillComplexArr(float arr[], int size) {
    for(int i  = 0 ; i < size ; i++) {
        char plus, im;
        cin >> arr[2 * i] >> plus >> im >> arr[2 * i + 1];
    }
}

void showArr(float arr[], int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[2 * i] << " + i" << arr[2 * i + 1] << endl;
    }
}

int main() {
    int quantity;
    cin >> quantity;
    float complexArr[quantity * 2];
    fillComplexArr(complexArr, quantity);
    sortComplex(complexArr, quantity);
    showArr(complexArr, quantity);
    return 0;
}


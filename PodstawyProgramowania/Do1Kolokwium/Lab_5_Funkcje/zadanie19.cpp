#include <iostream>
using namespace std;

float fun(float arr[], int size, int &maxIndex) {
    int maxValue = 0;
    maxIndex = 0;
    for(int i = 0 ; i < size ; i++) {
        for(int j = 0 ; j < size ; j++) {
            if(arr[j] > arr[i]) {
                maxIndex = j;
                maxValue = arr[j];
            }
        }
    }
    return maxValue;
}

int main() {
    float arr[6] = {1, 2, 3, 4, 5, 6};
    int maxIndex;
    cout << "Wartość: " << fun(arr, 6, maxIndex) << endl << "Index: " << maxIndex << endl;
    return 0;
}
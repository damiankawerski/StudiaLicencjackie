#include <iostream>
#include <algorithm>
using namespace std;

void show(int n) {
    cout << n << " ";
}

bool comparator(int x, int y) {
    return x > y;
}

void fun(int *arr, int n, int k, int* result) {
    int arrCopy[n];
    copy(arr, arr + n, arrCopy);
    sort(arrCopy, arrCopy + n, comparator);
    for(int i = 0 ; i < k ; i++) {
        result[i] = arrCopy[i];
    }
}


int main() {
    int arr[5] = {3, 5, 7, 1, 10};
    int n = 5;
    int k = 3;
    int result[k];
    fun(arr, n, k, result);
    for_each(result, result + k, show);
    return 0;
}
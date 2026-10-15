#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillArr(int* arr, int* end) {
    srand(time(0));
    while(arr < end) {
        *arr = rand() % 10;
        arr++;
    }
}

void showArr(int *arr, int* end) {
     while(arr  < end) {
        cout << *arr << " ";
        arr++;
    }
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    fillArr(arr, arr + n);
    showArr(arr, arr + n);
    delete[] arr;
    return 0;
}
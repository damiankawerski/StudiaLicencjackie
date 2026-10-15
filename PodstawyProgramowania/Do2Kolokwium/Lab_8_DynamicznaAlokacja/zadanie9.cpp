#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void rand_gen(int* arr, int* end) {
    srand(time(0));
    while(arr < end) {
        *arr = (rand() % 101) - 50;
        arr++;
    }
}

void swapW(int *x, int *y) {
    int temp = *x;
    *x =*y;
    *y = temp;
}

void bubble_sort(int size, int *arr) {
    for(int i = 0 ; i < size  ; i++) {
        for(int j = 0 ; j < size  ; j++) {
            if(arr[j] > arr[j + 1]) {
                swapW(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void show_by_m(int *arr, int size, int m) {
    int counter = 0;
    for(int i = 0 ; i < size - 1  ; i++) {
        for(int j = i + 1 ; j < size  ; j++) {
            if(arr[i] + arr[j] == m) {
                cout << arr[i] << ":" << arr[j] << endl;
                counter++;
            }
        }
    }
    cout << "Licznik: " << counter << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    int *arr = new int[n];
    rand_gen(arr, arr + n);
    bubble_sort(n, arr);
    show_by_m(arr, n, m);
    delete[] arr;
    return 0;
}
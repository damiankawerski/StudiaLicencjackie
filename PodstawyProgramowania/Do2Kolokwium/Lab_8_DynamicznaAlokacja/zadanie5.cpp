#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void rand_gen(float* arr, float* end) {
    srand(time(0));
    while(arr < end) {
        *arr = rand() % 10;
        arr++;
    }
}

float seq_rek(int size, float arr[]) {
    if(size == 0) return 0;
    return  pow((-1), size) * arr[size - 1] + seq_rek(size - 1, arr);
}


void seq(int size, float arr[]) {
    while(size >= 0) {
        cout << "[" << size << "]:" << seq_rek(size, arr) << endl;
        size--;
    }
}

int main() {
    int n;
    cin >> n;
    float *arr = new float[n];
    rand_gen(arr, arr + n);
    seq(n, arr);
    delete[] arr;
    return 0;
}
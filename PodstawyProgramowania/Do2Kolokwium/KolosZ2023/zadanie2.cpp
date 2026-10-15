#include <iostream>
using namespace std;

void reduce(float *input_start, float *input_end, float *dest, float (*fn)(float, float)) {
    while(input_start < input_end) {
        *dest = fn(*input_start, *(input_end - 1));
        input_start++;
        input_end--;
        dest++;
    }
}

float mul(float a, float b) {
    return a * b;
}

float amin(float a, float b) {
    if(a < b) return a;
    return b;
}

void show_arr(float *arr, int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    const int source_size = 6;
    const int dest_size = source_size / 2;
    
    float result1[dest_size];
    float result2[dest_size];
    float arr[source_size] = {1, 8, 4, 7, 9, 2};
    
    show_arr(arr, source_size);
    cout << endl;

    // Wywołanie funkcji reduce() z funkcjami pomocniczymi
    reduce(arr, arr + source_size, result1, mul);
    show_arr(result1, dest_size);
    cout << endl;

    reduce(arr, arr + source_size, result2, amin);
    show_arr(result2, dest_size);
    cout << endl;

    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

float vector_length(float x, float y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

void fun_arr(float *start, float *end, float *result, float (*fn)(float, float)) {
    for(int i = 0 ; start < end ; i++) {
        result[i] = fn(*start, *(start + 1));
        start++;
        start++;
    }
}

void show_vector_len(float* arr, int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << "     ";
    }
}


int main() {
    unsigned int N = 4;


    float *array = new float[2*N] {1.0 ,1.0, 2.0 ,1.0, 1.0, 3.0, 3.0, 1.0};
    float *result = new float[N];

    fun_arr(array, array + 2*N, result, vector_length);
    show_vector_len(result, N);


    delete[] result;
    delete[] array;

    return 0;
}
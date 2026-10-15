#include <iostream>
using namespace std;

unsigned int N;

float fun_aux(float a, float b, float c) {
    if(a > b && a > c) return a;
    if(b > a && b > c) return b;
    return c; 
}   

void fun_arr(float arr1[], float arr2[], float (*fun_wsk)(float, float, float)) {
    for(int i = 0 ; i < N ; i++) {
        arr2[i] = fun_wsk(arr1[3*i], arr1[3*i + 1], arr1[3*i + 2]);
    }
}

void show_arr(float* start, float* end) {
    while(start < end) {
        cout << *start << " ";
        start++;
    }
}

int main() {
    N = 4;
    float *arr1 = new float[N*3] {1.0,1.0,2.5,   2.0,1.0,-0.5,   -1.5,-3.0,-4.0,   0.0,0.0,0.0};
    float *arr2 = new float[N];
    fun_arr(arr1, arr2, fun_aux);
    show_arr(arr2, arr2 + N);
    delete arr1;
    delete arr2;
    return 0;
}
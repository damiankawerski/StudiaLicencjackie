#include <iostream>
#include <algorithm>
using namespace std;

void show(float n) {
    cout << n << " ";
}

void add_mat(float *matrix1, float *matrix2, int size) {
    for(int i = 0 ; i < size*size ; i++) {
            *matrix1 += *matrix2;
            matrix1++;
            matrix2++;
    }
 }


void subtract_mat(float *matrix1, float *matrix2, int size) {
    for(int i = 0 ; i < size*size ; i++) {
            *matrix1 -= *matrix2;
            matrix1++;
            matrix2++;
        }
}

void mat_operation(float *matrix1, float *matrix2, int size, void (*operation)(float*, float*, int)) {
    operation(matrix1, matrix2, size);
}

int main() {
    int size = 3;
    float matrix1[size*size] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    float matrix2[size*size] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    for_each(matrix1, matrix1 + size*size, show);
    cout << endl;
    for_each(matrix2, matrix2 + size*size, show);
    cout << endl;
    mat_operation(matrix1, matrix2, size, subtract_mat);
    for_each(matrix1, matrix1 + size*size, show);
    return 0;
}
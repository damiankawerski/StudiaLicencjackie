#include <iostream>
using namespace std;

void gen_mat(float **matrix, int n) {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < i * i + 1 ; j++) {
            matrix[i][j] = static_cast<float>(i + j) / 2;
        }
    }
}

void show_mat(float **matrix, int n) {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < i * i + 1 ; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    float **matrix = new float*[n];
    for(int i = 0 ; i < n ; i ++) {
        matrix[i] = new float[i * i + 1];
    }
    gen_mat(matrix, n);
    show_mat(matrix, n);
    for(int i = 0 ; i < n ; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

struct vec2D {
    double x;
    double y;
};

void diag_matrix(vec2D *arr_v, double **mat, int size) {
    for(int i = 0 ; i < size ; i++) {
        for(int j = 0 ; j < size ; j++) {
            if(i != j) {
                mat[i][j] = 0;
            }
            else {
                mat[i][i] = sqrt(pow(arr_v[i].x, 2) + pow(arr_v[i].y, 2));
            }
        }
    }
}

int main() {
    srand(time(0));
    int n = 4;
    vec2D *arr_v = new vec2D[n];

    double **mat = new double*[n];
    for(int i = 0 ; i < 4 ; i++) {
        mat[i] = new double[n];
    }

    for(int i = 0 ; i < n ; i++) {
        arr_v[i].x = (double)(rand() % 100) / (double)((rand() % 1000 ) + 100);
        arr_v[i].y = (double)(rand() % 100) / (double)((rand() % 1000 ) + 100);
    }

    diag_matrix(arr_v, mat, n);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0 ; i < n ; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    delete[] arr_v; 
    return 0;
}

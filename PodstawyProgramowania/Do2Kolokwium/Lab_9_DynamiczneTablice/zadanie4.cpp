#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void transform_matrix(float **&matrix, int mats, int rows) {
    float **arr = new float*[rows];
    for(int i = 0 ; i < rows ; i++) {
        arr[i] = new float[mats];
    }
    for(int i = 0; i < mats ; i++) {
        for(int j = 0 ; j < rows ; j++) {
            arr[j][i] = matrix[i][j];
        }
    }
    for(int i = 0 ; i < mats ; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = arr;
}

void show_arr(float **arr, int mats, int rows) {
    for(int i = 0 ; i < mats ; i++) {
        for(int j = 0 ; j < rows ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void fill_arr(float **arr, int mats, int rows) {
    srand(time(0));
    for(int i = 0 ; i < mats ; i++) {
        for(int j = 0 ; j < rows ; j++) {
            arr[i][j] = rand() % 10;
        }   
    }
}

int main() {
    int mats, rows;
    mats = 4;
    rows = 5;
    float** matrix = new float*[mats];
    for(int i = 0 ; i < mats ; i++) {
        matrix[i] = new float[rows];
    }
    fill_arr(matrix, mats, rows);
    show_arr(matrix, mats, rows);
    cout << endl;
    transform_matrix(matrix, mats, rows);
    show_arr(matrix, rows, mats);

    for(int i = 0 ; i < mats ; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
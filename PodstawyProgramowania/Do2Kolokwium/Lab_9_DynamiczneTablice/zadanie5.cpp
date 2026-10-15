#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void change_matrix(int **&matrix, int mats, int rows) {
    int **arr = new int*[mats];
    for(int i = 0 ; i < mats ; i++) {
        arr[i] = new int[rows];
    }
    for(int i = 0 ; i < mats ; i++) {
        for(int j = 0 ; j < rows ; j++) {
            if(i + 1 == mats) {
                arr[0][j] = matrix[mats - 1][j];
            } 
            else {
                arr[i+1][j] = matrix[i][j];
            }
        }
    }
    for(int i = 0 ; i < mats ; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = arr;
}

void fill_arr(int **arr, int mats, int rows) {
    srand(time(0));
    for(int i = 0 ; i < mats ; i++) {
        for(int j = 0 ; j < rows ; j++) {
            arr[i][j] = rand() % 10;
        }   
    }
}

void show_arr(int **arr, int mats, int rows) {
    for(int i = 0 ; i < mats ; i++) {
        for(int j = 0 ; j < rows ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mats, rows;
    mats = 4;
    rows = 5;
    int **matrix = new int*[mats];
    for(int i = 0 ; i < mats ; i++) {
        matrix[i] = new int[rows];
    }
    fill_arr(matrix, mats, rows);
    show_arr(matrix, mats, rows);
    cout << endl;
    change_matrix(matrix, mats, rows);
    show_arr(matrix, mats, rows);
    for(int i = 0 ; i < mats ; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
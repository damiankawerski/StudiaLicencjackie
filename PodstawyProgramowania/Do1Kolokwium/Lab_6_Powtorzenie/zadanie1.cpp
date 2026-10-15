#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int rows = 7;
const int cols = 7;


void matrix_average(float matrix[rows][cols]) {
    float temp[rows][cols];
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            float sum = matrix[i][j];
            float counter = 1;
            if(i - 1 >= 0) {
                sum += matrix[i - 1][j];
                counter++;
            }
            if(j - 1 >= 0) {
                sum += matrix[i][j - 1];
                counter++;
            }
            if(i + 1 < rows) {
                sum += matrix[i + 1][j];
                counter++;
            }
            if(j + 1 < cols) {
                sum += matrix[i][j + 1];
                counter++;
            }
            temp[i][j] = sum/counter;
        }
    }
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

void show_matrix(float matrix[rows][cols]) {
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    float matrix[rows][cols];
    srand(time(0));
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
    show_matrix(matrix);

    matrix_average(matrix);

    cout << endl << endl;

    show_matrix(matrix);

    return 0;
}


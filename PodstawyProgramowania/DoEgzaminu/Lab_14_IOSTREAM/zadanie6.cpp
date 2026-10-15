#include <iostream>
using namespace std;

struct Matrix {
    int cols;
    int rows;
    int **matrix;

    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        matrix = new int*[rows];
        for(int i = 0 ; i < rows ; i++) {
            matrix[i] = new int[cols];
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = i * rows + j;
            }
        }
    }

    ~Matrix() {
        for(int i = 0 ; i < rows ; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

void write_mat(char* plik, Matrix &arr, int rows, int cols) {
    FILE* file = fopen(plik, "w");
    fprintf(file, "%d ", rows);
    fprintf(file, "%d\n", cols);
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            fprintf(file, "%d ", arr.matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void read_mat(char* plik, Matrix &arr, int &rows, int &cols) {
    FILE* file = fopen(plik, "r");
    fscanf(file, "%d", &rows);
    fscanf(file, "%d", &cols);
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            fscanf(file, "%d", &arr.matrix[i][j]);
        }
    }
    fclose(file);
}

int main() {
    char sciezka[30] = "zadanie6.txt";
    int rows = 4;
    int cols = 4;
    Matrix arr1(rows, cols);
    Matrix arr2(rows, cols);
    write_mat(sciezka, arr1, rows, cols);
    int row;
    int col;
    read_mat(sciezka, arr2, row, col);
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            cout << arr2.matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

struct Matrix {
    short cols;
    short rows;
    int **matrix;

    Matrix(short rows, short cols) : rows(rows), cols(cols) {
        matrix = new int*[rows];
        for(int i = 0 ; i < rows ; i++) {
            matrix[i] = new int[cols];
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = i * cols + j;
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

void write_mat(char* plik, Matrix &arr, short rows, short cols) {
    FILE* file = fopen(plik, "wb");
    fwrite(&rows, sizeof(rows), 1, file);
    fwrite(&cols, sizeof(cols), 1, file);
    for(int i = 0 ; i < rows ; i++) {
        fwrite(arr.matrix[i], sizeof(arr.matrix[0][0]), cols, file);
    }
    fclose(file);
}

void read_mat(char* plik, Matrix &arr, int &rows, int &cols) {
    FILE* file = fopen(plik, "rb");
    fread(&rows, sizeof(rows), 1, file);
    fread(&cols, sizeof(cols), 1, file);
    for(int i = 0 ; i < rows ; i++) {
        fread(arr.matrix[i], sizeof(arr.matrix[0][0]), cols, file);
    }
    fclose(file);
}

int main() {
    char sciezka[30] = "zadanie7.bin";
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
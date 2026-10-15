#include <iostream>
using namespace std;

void dyadic(int **matrix1, int** matrix2, int** result, int W1, int K1, int W2, int K2) {
    
    for(int i = 0 ; i < W1 ; i++) {
        for(int j = 0 ; j < K2 ; j++) {
            result[i][j] = 0;
        }
    }

    for(int i = 0 ; i < W1 ; i++) {
        for(int j = 0 ; j < K2 ; j++) {
            for(int k = 0 ; k < K1 ; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void show_arr(int **arr, int W, int K) {
    for(int i = 0 ; i < W ; i++) {
        for(int j = 0 ; j < K ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void fill_arr(int **arr, int W, int K) {
    for(int i = 0 ; i < W ; i++) {
        cout << "wpisz" << i << "wiersz: " << endl;
        for(int j = 0 ; j < K ; j++) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    int W1, K1, W2, K2;
    W1 = 3;
    K1 = 3;
    W2 = 3;
    K2 = 3;
    if(W2 != K1) return 0;
    int **matrix1 = new int*[W1];
    for(int i = 0 ; i < W1 ; i ++) {
        matrix1[i] = new int[K1];
    }
    int **matrix2 = new int*[W2];
     for(int i = 0 ; i < W2 ; i ++) {
        matrix2[i] = new int[K2];
    }
    int **result = new int*[W1];
     for(int i = 0 ; i < W1 ; i ++) {
        result[i] = new int[K2];
    }
    cout << "Wypelnij 1 macierz" << endl;
    fill_arr(matrix1, W1, K1);
    cout << "Wypelnij 2 macierz" << endl;
    fill_arr(matrix2, W2, K2);
    show_arr(matrix1, W1, K1);
    cout << " * " << endl;
    show_arr(matrix2, W2, K2);
    cout << " = " << endl;
    dyadic(matrix1, matrix2, result, W1, K1, W2, K2);
    show_arr(result, W1, K2);

    for(int i = 0 ; i < W1 ; i++) {
        delete[] matrix1[i];
    }
      for(int i = 0 ; i < W2 ; i++) {
        delete[] matrix2[i];
    }
      for(int i = 0 ; i < W1 ; i++) {
        delete[] result[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] result;
    return 0;
}
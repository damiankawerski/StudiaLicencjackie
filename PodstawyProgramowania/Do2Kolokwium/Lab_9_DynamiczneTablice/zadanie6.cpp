#include <iostream>
using namespace std;


void dyadic(int *vector1, int* vector2, int** result, int size1, int size2) {
    for(int i = 0 ; i < size1 ; i++) {
        for(int j = 0 ; j < size2 ; j++) {
            result[i][j] = vector1[i] * vector2[j];
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

void fill_arr(int *arr, int size) {
    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }
}

int main() {
    int size1 = 5;
    int size2 = 6;
    int *vector1 = new int[size1];
    int *vector2 = new int[size2];
    int **result = new int*[size1];
    for(int i = 0 ; i < size1 ; i ++) {
        result[i] = new int[size2];
    }

    cout << "vector1 : " << endl;
    fill_arr(vector1, size1);
    cout << "vector2 : " << endl;
    fill_arr(vector2, size2);
    cout << endl;
    dyadic(vector1, vector2, result, size1, size2);
    show_arr(result, size1, size2);


    for(int i = 0 ; i < size1 ; i ++) {
        delete[] result[i];
    }
    delete[] result;
    delete[] vector1;
    delete[] vector2;
    return 0;
}
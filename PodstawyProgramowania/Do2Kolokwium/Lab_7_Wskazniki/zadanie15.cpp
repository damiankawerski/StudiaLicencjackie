#include <iostream>
using namespace std;

void multipyMatrix(int *matrix1, int *matrix2, int *result) {
    for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            for(int k = 0 ; k < 3 ; k++) {
                *(result + (i * 3 + j)) += *(matrix1 + (i * 3 + k)) * *(matrix2 + (k * 3 + j));
            }
        }
    }
}

void showMatrix(int *start, int *end) {
    while(start  < end) {
        cout << *start << " ";
        start++;
    }
}

int main() {
    int matrix1[9] = {1, 2 ,3 , 5, 4 ,6, 7, 8, 9};
    int matrix2[9] = {1, 2 ,3 ,4, 5 ,6, 7, 8, 9};
    int result[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    multipyMatrix(matrix1, matrix2, result);
    showMatrix(result, result + 9);
    return 0;
}
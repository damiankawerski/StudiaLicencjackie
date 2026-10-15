#include <iostream>
using namespace std;

struct matrix{
    float arr[3][3];
};

void print_mat(matrix array) {
    for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            cout << array.arr[i][j] << " ";
        }
        cout << endl;
    }
}

void add_mat(matrix &array, float number) {
     for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            array.arr[i][j] += number;
        }
    }
}

int main() {
    float number;
    cin >> number;
    matrix array;
    for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            array.arr[i][j] = i + j;
        }
    }
    print_mat(array);
    add_mat(array, number);
    cout << endl;
    print_mat(array);
    return 0;
}
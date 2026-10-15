#include <iostream>



class Matrix3x3 {
public:
    float arr[3][3];

    void print() {
        for(int i = 0 ; i < 3 ; i++) {
            for(int j = 0 ; j < 3 ; j++) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void add(float n) {
        for(int j = 0 ; j < 3 ; j++) {
            arr[j][j] += n;
        }
    }
};

void fill_matrix3x3(Matrix3x3 &arr) {
    float sum = 0;
    for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            arr.arr[i][j] = sum++;
        }
    }
}



int main() {
    float n;
    std::cin >> n;
    Matrix3x3 arr;
    fill_matrix3x3(arr);
    arr.print();
    std::cout << std::endl;
    arr.add(n);
    arr.print();
    return 0;
}
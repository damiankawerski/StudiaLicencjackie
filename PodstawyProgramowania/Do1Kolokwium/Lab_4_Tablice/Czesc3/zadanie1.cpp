#include <iostream>     
using namespace std; 
int main() {
    const int size = 16;
    int matrix[16][16];
    for(int i = 0 ; i < size ; i++) {
        for(int j = 0 ; j < size ; j++) {
            matrix[i][j] = i * j;
        }
    }
        for(int i = 0 ; i < size ; i++) {
            for(int j = 0 ; j < size ; j++) {
            cout << hex << uppercase << matrix[i][j] << '\t';
        }
        cout << endl;
    }   
    return 0;
}

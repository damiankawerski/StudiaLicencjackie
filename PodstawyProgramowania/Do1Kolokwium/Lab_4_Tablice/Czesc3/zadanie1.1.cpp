#include <iostream>     
using namespace std; 
int main() {
    const int size = 16;
    int matrix[size * size];
    for(int i = 0  ; i < size ; i++) {
      for(int j = 0 ; j < size ; j++) {
        matrix[i * size + j] = i * j;
      }
    }
        for(int i = 0 ; i < size ; i++) {
            for(int j = 0 ; j < size ; j++) {
            int result = matrix[i * size + j];
            if(result < 0x10) {
                cout << '0';
            }
            cout << hex << uppercase << result << '\t';
        }
        cout << endl;
    }   
    return 0;
}

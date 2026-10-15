#include <iostream>
using namespace std;

void fill_vector1(int* vector,unsigned int n) {
    for(int i = 0 ; i < n ; i++) {
        vector[i] = (2 * i) + 1;
    }
}

void fill_vector2(int* vector,unsigned int n) {
    for(int i = 0 ; i < n; i++) {
        vector[i] = n - i;
        
    }
}

int vector_scalar(int* vector1, int *vector2,unsigned int n) {
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        sum += vector1[i] * vector2[i];
    }
    return sum;
}


int main() {
    unsigned int n;
    cin >> n;
    int *vector1 = new int[n];
    int *vector2 = new int[n];
    fill_vector1(vector1, n);
    fill_vector2(vector2, n);
    for(int i = 0 ; i < n ; i++) {
        cout << vector1[i] << " ";
    }
    cout << endl;
    for(int i = 0 ; i < n ; i++) {
        cout << vector2[i] << " ";
    }
    cout << endl;
    cout << vector_scalar(vector1, vector2, n);
    delete[] vector1;
    delete[] vector2;
    return 0;
}
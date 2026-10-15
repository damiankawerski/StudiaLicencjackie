#include <iostream>
using namespace std;

void dyadic(float vector1[], float vector2[], float result[], int size) {
    for(int i = 0 ; i < size ; i++) {
        for(int j = 0 ; j < size ; j++) {
            result[i * size + j] = vector1[i]*vector2[j];
        }
    }
}

void showResult(float result[], int size) {
    for(int i = 0 ; i < size ; i++) {
        for(int j = 0 ; j < size ; j++) {
            cout << result[i * size + j] << " ";
        }
        cout << endl;
    }
}

int main () {
    int size = 3;
    float vector1[size], vector2[size], result[size * size];
    cout << "vector1: " << endl;
    for(int i = 0 ; i < size ; i++) {
        cin >> vector1[i];
    }
    cout << "vector2: " << endl;
    for(int i = 0 ; i < size ; i++) {
        cin >> vector2[i];
    }
    dyadic(vector1, vector2, result, size);
    showResult(result, size);
    return 0;
}

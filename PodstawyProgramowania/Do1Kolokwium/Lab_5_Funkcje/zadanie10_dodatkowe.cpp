#include <iostream>
using namespace std;

void vector_multip(const int vector1[3], const int vector2[3], double result_vector[3]) {
    result_vector[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    result_vector[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    result_vector[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
}

int main() {
    int vector1[3];
    int vector2[3];
    double result[3];
    for(int i = 0 ; i < 3 ; i++) {
        cin >> vector1[i] ;
    }
    for(int i = 0 ; i < 3 ; i++) {
        cin >> vector2[i];
    }

    vector_multip(vector1, vector2, result);

    for(int i = 0 ; i < 3 ; i++) {
        cout << result[i] << " ";
    }
    return 0;
}
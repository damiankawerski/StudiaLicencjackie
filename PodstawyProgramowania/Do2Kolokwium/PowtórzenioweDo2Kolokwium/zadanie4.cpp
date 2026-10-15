#include <iostream>
using namespace std;

float sum(float* arr, int size) {
    float sum = 0;
    for(int i = 0 ; i < size ; i++) {
        sum += arr[i];
    }
    return sum;
}

void show_array(float* arr, int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << "  ";
    }
}

int main() {


    int n;
    cout << "podaj liczbe wierszy: ";
    cin >> n;
    int *arr = new int[n];
    for(int i = 0 ; i < n ; i++) {
        cout << "podaj rozmiar wiersza numer " << i << endl;
        cin >> arr[i];
    }
    
    float **arr2d = new float*[n];
    for(int i = 0 ; i < n ; i++) {
        arr2d[i] = new float[arr[i]];
    }
    float *result = new float[n];

    for(int i = 0 ; i < n ; i++) {
        cout << "podaj wiersz numer " << i << endl;
        for(int j = 0 ; j < arr[i] ; j++) {
            cin >> arr2d[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++) {
        result[i] = sum(arr2d[i], arr[i]);
    }

    show_array(result, n);


    delete[] result;
    for(int i = 0 ; i < n ; i++) {
        delete[] arr2d[i];
    }
    delete[] arr;
    delete[] arr2d;
    return 0;
}
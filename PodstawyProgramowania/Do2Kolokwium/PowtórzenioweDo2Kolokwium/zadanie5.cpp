#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void random_fill_arr(int **arr, int n, int m) {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < 2*m ; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}

void show_arr2d(float **arr, int n, int m) {
     for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}



void make_it_float(int **arr2d, float **arr2d_2, int n, int m) {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j <  m ; j++) {
            if(arr2d[i][2 * j] > arr2d[i][2 * j + 1]) {
                arr2d_2[i][j] = static_cast<float>(arr2d[i][2 * j]) + static_cast<float>(arr2d[i][2 * j + 1]) / 10;
            }
            else {
                arr2d_2[i][j] = static_cast<float>(arr2d[i][2 * j + 1]) + static_cast<float>(arr2d[i][2 * j]) / 10;
            }      
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;



    int** arr2d = new int*[n];
    for(int i = 0 ; i < n ; i++) {
        arr2d[i] = new int[2*m];
    }

    float** arr2d_2 = new float*[n];
    for(int i = 0 ; i < n ; i++) {
        arr2d_2[i] = new float[m];


    }



    random_fill_arr(arr2d, n, m);
    make_it_float(arr2d, arr2d_2, n, m);
    show_arr2d(arr2d_2, n, m);



    for(int i = 0 ; i < n ; i++) {
        delete[] arr2d[i];
    }
    delete[] arr2d;
    for(int i = 0 ; i < n ; i++) {
        delete[] arr2d_2[i];
    }
    delete[] arr2d_2;
    return 0;
}
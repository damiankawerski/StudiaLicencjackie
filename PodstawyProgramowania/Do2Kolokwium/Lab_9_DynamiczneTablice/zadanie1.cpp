#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fill_arr(int ***arr, int n, int m, int o) {
    srand(time(0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
           for(int k = 0 ; k < o ; k++) {
                arr[i][j][k] = rand() % 10;
           }
        }
    }
}

void show_arr(int ***arr, int n, int m, int o) {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            for(int k = 0 ; k < o ; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n, m, o;
    cin >> n >> m >> o;
    int*** arr = new int**[n];

    for(int i = 0 ; i < n ; i++) {
        arr[i] = new int*[m];
        for(int j = 0 ; j < m ; j++) {
            arr[i][j] = new int[o]; 
        }
    }

    fill_arr(arr, n, m, o);
    show_arr(arr, n, m, o);

    for(int i = 0 ; i < n ; i++) {
        for(int  j = 0 ; j < m ; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }

    delete[] arr;
    return 0;
}
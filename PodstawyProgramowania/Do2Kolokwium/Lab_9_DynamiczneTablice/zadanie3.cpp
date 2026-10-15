#include <iostream>
using namespace std;

//n - kolumny, m - wiersze 

int check_zeros(int **arr, int n, int m) {
    //sprawdz wiersze:
    for(int i = 0 ; i < n ; i++) {
        if(arr[i][0] != 0) {
            return -1;
        }
        if(arr[i][m - 1] != 0) {
            return -1;
        }
    }
    //sprawdz kolumny
    for(int i = 0 ; i < m ; i++) {
        if(arr[0][i] != 0) {
            return -1;
        }
        if(arr[n - 1][i] != 0) {
            return -1;
        }
    }
    return 0;
}

void fill_arr(int **arr, int n, int m) {
    for(int i = 0 ; i < n ; i++) {
        cout << "Wpisz " << i << " wiersz: " ;
        for(int j = 0 ; j < m ; j++) {
        cin >> arr[i][j];
        }
    }
}


int main() {
    int n;
    int m;
    cin >> n >> m;
    int **arr = new int*[n];
    for(int i = 0 ; i < n ; i++) {
        arr[i] = new int[m];
    }

    fill_arr(arr, n, m);
    cout << check_zeros(arr, n, m) << endl;

     for(int i = 0 ; i < n ; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
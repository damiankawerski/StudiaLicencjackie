#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void randomzie_arr(int *arr, int size) {
    srand(time(0));
    for(int i = 0 ; i < size ; i++) {
        arr[i] = rand() % 6;
    }
}

void show_same_elements(int *arr1, int *arr2, int *arr3, int n, int m, int o) {
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while(i < n && j < m && k < o) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            cout << arr1[i] << " ";
            i++;
            j++;
            k++;
        }
        else if
    }
    
}

int main() {
    int n, m, o;
    cin >> n >> m >> o;
    int* arrn = new int[n];
    int* arro = new int[o];
    int* arrm = new int[m];
    randomzie_arr(arrn, n);
    randomzie_arr(arro, o);
    randomzie_arr(arrm, m);
    sort(arrn, arrn + n);
    sort(arro, arro + o);
    sort(arrm, arrm + m);
}
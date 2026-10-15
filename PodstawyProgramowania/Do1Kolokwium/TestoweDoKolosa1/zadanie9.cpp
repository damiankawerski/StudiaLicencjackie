#include <cstdio>

using namespace std;

int matRows(int mat[], int n, int m) {
    int counter = 0;
    for(int i = 0 ; i < n ; i++) {
        bool isSorted = true;
        for(int j = 0 ; j < m - 1 ; j++) {
            if(mat[i * m + j] > mat[i * m + j + 1]) {
                isSorted = false;
                break;
            }
        }
        if(isSorted) counter++;
    }
    return counter;
}

int main() {
    int n = 2;
    int m = 3;
    int mat[n * m] = {1, 6, 3, 
                      5, 5, 7};
    
    int result = matRows(mat, n, m);
    printf("Liczba posortowanych wierzsy: %d\n", result);
    return 0;


}   
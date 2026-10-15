#include <iostream>
using namespace std;

bool columSumComp(int arr[], int n, int m) {
    int sumaObecnejKolumny = 0;
    int sumaNastepnejKolumny = 0;
    for(int i = 0 ; i < m - 1 ; i++) {


        for(int j = 0 ; j < n ; j++) {
            sumaObecnejKolumny += arr[j * m + i];
            sumaNastepnejKolumny += arr[j * m + i + 1];
            if(sumaObecnejKolumny >= sumaNastepnejKolumny) return false;
    }
}
return true;
}

int main() {
    int n = 3; // Wiersze
    int m = 10; // Kolumny
    int macierz[n * m] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                          11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                          21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    
    cout << columSumComp(macierz, n, m) << endl;
    
}
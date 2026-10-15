#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    srand(time(0));
    int N, M, O;
    cin >> N >> M >> O;
    int arr[N][M][O];
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            for(int k = 0 ; k < O ; k++) {
                arr[i][j][k] = rand();
            }
        }
    }
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            for(int k = 0 ; k < O ; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl << endl << endl;
    }
}
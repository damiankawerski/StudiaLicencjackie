#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    const int n = 6;
    int arr[n];
    int temp[n];
    srand(time(0));

    for(int i = 0 ; i < n ; i++) {
        arr[i] = rand() % 10;
    }
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int m;
    cout << "ile do przesuniecia: " << endl;
    cin >> m;
    //***********************************************

        for(int i = 0 ; i < n ; i++) {
           int newIndex = (i + m ) % n;
           temp[newIndex] = arr[i];
       
        }
    
    //**********************************************
    for(int i = 0 ; i < n ; i++) {
        arr[i] = temp[i];
    }
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
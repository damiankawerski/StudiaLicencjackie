#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomizeArray(float arr[], int size) {
    srand(time(0));
     for(int i = 0 ; i < size ; i++) {
        arr[i] = rand() % 10;
    }
}

int main() {
    int size = 15;
    int cinAmount = 5;
    int indexArray[cinAmount];
    float mainArray[size];
    for(int i = 0 ; i < cinAmount ; i++) {
        cin >> indexArray[i];
    }
    randomizeArray(mainArray, size);
    
    for(int i = 0 ; i < cinAmount ; i++) {
        if(indexArray[i] < size) {
            cout << "[" << indexArray[i] << "]: " << mainArray[indexArray[i]] << endl;
        }
        else cout << "[" << indexArray[i] << "]: " << "Bład" << endl;
    }
    return 0;
}
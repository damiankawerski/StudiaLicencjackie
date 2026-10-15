#include <iostream>
#include <cstring>
using namespace std;

void null_set(void* arr1, void* arr2, int n, size_t size) {
    for(int i = 0 ; i < n ; i++) {
        if(memcmp(static_cast<char*>(arr1) + i * size, 
                  static_cast<char*>(arr2) + i * size,
                  size) == 0) {
            memset(static_cast<char*>(arr1) + i * size, 0, size);
            memset(static_cast<char*>(arr2) + i * size, 0 ,size);
        }
    }
}

int main() {
    int n = 4;
    int arr1[n] = {8, 9, 10, 11};
    int arr2[n] = {8, 3, 10, 4};
    size_t size = sizeof(arr1) / sizeof(arr1[0]);
    null_set(arr1, arr2, n, size);

    for(int i = 0 ; i < n ; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for(int i = 0 ; i < n ; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}


// do zrobienia bez memset i memcmp
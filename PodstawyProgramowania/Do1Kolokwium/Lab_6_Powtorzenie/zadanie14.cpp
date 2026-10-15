#include <iostream>
using namespace std;

int fun(int arr[], unsigned int size, bool logic) {
    if(logic == 0) return 0;
    for(int i = 0 ; i < size - 1 ; i++) {
        if(arr[i] == arr[i + 1]) 
            return arr[i];
    }
    
    return 0;
}
int main() {
    int size = 6;
    int arr[size] = {1, 2, 3, 4, 4, 6};
    cout << fun(arr, size, false) << endl;
    return 0;
}
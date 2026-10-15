#include <iostream> 
using namespace std;
int main() {
    float arr[6] = {2, 10, 3, 2, 10, 9};
    int max_value = 0;
    for(int i = 0 ; i < 6 ; i++) {
        if(max_value < arr[i]) {
            max_value = arr[i];
        }
    }
    for(int i = 0 ; i < 6 ; i++) {
        if(arr[i] == max_value) {
            cout << i << endl;
        }
    }
    
    return 0;
}
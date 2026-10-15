#include <iostream>
#include <algorithm>
using namespace std;


void show(int n) {
    cout << n << " ";
}


bool condition(int n) {
    int arr[10];
    for(int i = 0 ; i < 10 ; i++) {
        arr[i] = 0;
    }
    while(n != 0) {
        int x = n % 10;
        if(arr[x] > 0) return true;
        arr[x]++;
        n /= 10;
    }
    return false;
}

void action(int &n) {
    int nReversed = 0;
    while(n != 0) {
        int lastNumber = n % 10;
        nReversed = nReversed * 10 + lastNumber;
        n /= 10;
    }
    n = nReversed;
}

void modify_array(int *arr, int size, bool (*condition)(int), void (*action)(int&)) {
    for(int i = 0 ; i < size ; i++) {
        if((*condition)(arr[i])) {
            (*action)(arr[i]);
        }
    } 
}

int main() {
    int size = 5;
    int arr[] = {432, 113, 2123, 123, 0};
    modify_array(arr, size, condition, action);
    for_each(arr, arr + size, show);
    cout << endl;
    modify_array(arr, size, condition, action);
    for_each(arr, arr + size, show);
    return 0;
}
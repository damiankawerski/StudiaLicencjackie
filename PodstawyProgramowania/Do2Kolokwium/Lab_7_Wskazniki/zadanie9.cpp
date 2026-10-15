#include <iostream>
using namespace std;

void showMatrix(int *start, int *end) {
    while(start  < end) {
        cout << *start << " ";
        *start++;
    }
}

int main() {
    int arr[8] = {11, 2 ,3 ,4 ,5 ,6 ,7, 8};
    showMatrix(arr, arr + 8);
    return 0;
}
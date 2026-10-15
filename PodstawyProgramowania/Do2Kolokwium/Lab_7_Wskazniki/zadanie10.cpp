#include <iostream>
using namespace std;

void reverseList(int* start, int size) {
    int* end = start + size - 1;
    while(start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;       
        start++;
        end--; 
    }
}

void showList(int *start, int *end) {
    while(start  < end) {
        cout << *start << " ";
        *start++;
    }
}

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    reverseList(arr, 6);
    showList(arr, arr + 6);
    return 0;
}
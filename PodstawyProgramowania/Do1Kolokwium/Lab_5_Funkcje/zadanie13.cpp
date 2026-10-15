#include <iostream>
using namespace std;

int zerowanie(int arr[],int size,int start,int end) {
    if(end < start) return -1;
    for(int i = 0 ; i < size ; i++) {
        if(arr[i] < start || arr[i] > end) arr[i] = 0;
    }
    return 0;
}


int main() {
    int start;
    int end;
    int size;
    cin >> size;
    cin >> start;
    cin >> end;
    int arr[size];
    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }

    zerowanie(arr, size, start, end);

     for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
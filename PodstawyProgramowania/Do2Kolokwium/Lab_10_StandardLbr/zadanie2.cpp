#include <iostream>
#include <algorithm>
using namespace std;

void show(float n) {
    cout << n << " ";
}

int main() {
    float arr[7] = {1, 2, 3, 4, 5, 6, 7};
    for_each(arr, arr + 7, show);
    return 0;
}
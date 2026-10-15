#include <iostream>
#include <algorithm>
using namespace std;

bool comparator(int x, int y) {
    return x > y;
}

int comparator2(const void* a, const void* b) {
    int arg1 = (*(int*)a);
    int arg2 = (*(int*)b);
    if(arg1 < arg2) return -1;
    if(arg1 > arg2) return 1;
    return 0;
}

void show(int x) {
    cout << x << " ";
}



int main() {
    int arr1[4] = {3, 1, 5, 2};
    sort(arr1, arr1 + 4, comparator); 
    for_each(arr1, arr1 + 4, show);
    cout << endl << endl;
    qsort(arr1, 4, sizeof(int), comparator2);
    for_each(arr1, arr1 + 4, show);
    return 0;
}
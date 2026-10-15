#include <iostream>
using namespace std;

void swap(int *start, int *end) {
    int temp = *start;
    *start = *end;
     *end = temp;
}

int* fun(int *start, int *end, bool &f) {
    while(start < end) {
        while((*start % 2 != 0) && (start < end)) {
            start++;
        }
        while((*end % 2 == 0) && (start < end)) {
            end--;
        }
        if(start < end) {
            swap(start, end);
            f = true;
        }
    }
    return start;
}

void showList(int *start, int *end) {
    while(start  < end) {
        cout << *start << " ";
        start++;
    }
}
 
int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    bool f;
    showList(arr, arr + 6);
    int firstEven = *fun(arr, arr + 6, f);
    fun(arr, arr + 6, f);
    cout << endl;
    showList(arr, arr + 6);
    cout << endl;
    cout << firstEven << endl;
    return 0;
}

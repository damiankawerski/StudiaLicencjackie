#include <iostream>
#include <algorithm>
using namespace std;

bool is_unique(unsigned short* arr, int size) {
    for(int i = 0 ; i < size ; i++) {
        for(int j = i + 1 ; j < size ; j++) {
            if(arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}

bool is_strictly_increasing(unsigned short* arr, int size) {
    return(is_sorted(arr, arr + size) && is_unique(arr, size));
}

int bitReading(unsigned short x, int n) {
    int mask = (1 << n);
    return ((x & mask) != 0);
}

bool are_zero_even_bits(unsigned short* arr, int size) {
    int counter = 0;
    for(int i = 0 ; i < size ; i++) {
        int counter_cond = 0;
        for(int j = 0 ; j < 16 ; j+=2) {
            if(bitReading(arr[i], j) == 0) {
                counter_cond++;
            }
        }
        if(counter_cond == 8) counter++;
    }
    return counter == size;
}

unsigned short* find_subset(unsigned short* arr, int size, bool (*fn)(unsigned short*, int size), int &ref) {
    unsigned short* result = nullptr;
    int max_size = 0;
    
    for(int i = 0 ; i < size ; i++) {
        for(int j = i + 1 ; j <= size ; j++) {
            if(fn(arr + i, j - i)) {
                if(max_size < (j - i)) {
                    max_size = j - i;
                    result = arr + i;
                }
            }
        }
    }
    ref = max_size;
    return result;
}

void show_arr(unsigned short* begin, unsigned short* end) {
    while(begin < end) {
        cout << *begin << " ";
        begin++;
    }
    cout << endl;
}

int main() {
    int size = 10;
    int returned_size;
    unsigned short arr[] = {1, 2, 5, 2, 2, 10, 11, 12, 8, 3};
    unsigned short* begin = find_subset(arr, size, is_strictly_increasing, returned_size);
    show_arr(begin, begin + returned_size);
    begin = find_subset(arr, size, are_zero_even_bits, returned_size);
    show_arr(begin, begin + returned_size);
    return 0;
}
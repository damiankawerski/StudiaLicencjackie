#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int comparator2(const void* a, const void* b) {
    const char* strA = *(const char **)a;
    const char* strB = *(const char **)b; 

    int lenA = strlen(strA);
    int lenB = strlen(strB);

    int i = 0;
    while (i < lenA && i < lenB) {
        if (strA[lenA - 1 - i] < strB[lenB - 1 - i]) {
            return -1; // strA mniejsze od strB
        } else if (strA[lenA - 1 - i] > strB[lenB - 1 - i]) {
            return 1;  // strA większe od strB
        }
        i++;
    }

    // Jeżeli dotarliśmy do tego miejsca, oznacza to, że napisy są równe
    return 0;
    
}

int main() {
    const char *str1[] = {"banana", "grape", "apple", "peach", "coconut", "steak"};
    int n = sizeof(str1)/sizeof(str1[0]);
    qsort(str1, n, sizeof(str1[0]), comparator2);
    for(int i = 0 ; i < 6 ; i++) {
        cout << str1[i] << endl;
    }
    return 0;
}


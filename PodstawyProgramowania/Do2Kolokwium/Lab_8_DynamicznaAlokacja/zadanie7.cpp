#include <iostream>
using namespace std;

void swap1(void* a , void* b, size_t size) {
    char* p = (char*)a;
    char* q = (char*)b;
    char tmp;

    for(int i = 0 ; i < size ; i++) {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

int main() {
    int x = 4;
    int y = 6;
    swap1(&x, &y, sizeof(int));
    cout << x << " " << y << endl;
    return 0;
}
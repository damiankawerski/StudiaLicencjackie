#include <iostream>
using namespace std;

unsigned char fun(unsigned char v, int b, bool f) {
    
    if(f) {
        v = (v & ~(0b11110000));
        v = (v ^ 0b00001111);
    }
    v = (v ^ (1 << b));
    return v;
}

int main() {
    unsigned char v = 13;
    int b = 6;
    bool f = true;
    cout << static_cast<int>(fun(v, b, f)) << endl;
    return 0;
}
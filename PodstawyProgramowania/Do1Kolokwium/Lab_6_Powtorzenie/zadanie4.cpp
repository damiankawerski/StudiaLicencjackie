#include <iostream>
using namespace std;

void bitSet1(unsigned int &x, int n) {
    int mask = (1 << n);
    x = (x | mask);
}

void bitSet0(unsigned int &x, int n) {
    int mask = (1 << n);
    x = (x & ~mask);
}

void bitReverse(unsigned int &x, int n) {
    int mask = (1 << n);
    x = (x ^ mask);
}


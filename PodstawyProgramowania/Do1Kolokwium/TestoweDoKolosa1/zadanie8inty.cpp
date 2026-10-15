#include <iostream>
using namespace std;

void bitsSwap(unsigned char &s) {
    unsigned char maskY = 0b00001111;
    unsigned char maskO = 0b11110000;

    unsigned char sY = s & maskY;
    unsigned char sO = s & maskO;

    s = (sY << 4) | (sO >> 4);
}

void negateTPos(unsigned char &s, unsigned char t) {
    s = s ^ (1 << (t % 8));
}


int main(void) {
    unsigned int s, t;
    cin >> t >> s;
    unsigned char sChar, tChar;
    sChar = (unsigned char)s;
    tChar = (unsigned char)t;
    cout << "before: " << (int)sChar << endl;
    bitsSwap(sChar);
    cout << "after 1: " << (int)sChar << endl;
    negateTPos(sChar, tChar);
    cout << "after 2: " << (int)sChar << endl;
    return 0;
}
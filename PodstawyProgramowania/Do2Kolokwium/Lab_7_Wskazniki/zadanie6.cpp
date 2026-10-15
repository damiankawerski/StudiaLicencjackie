#include <iostream>
using namespace std;

void  fun(int word, unsigned char *b1, unsigned char *b2,unsigned char *b3,unsigned char *b4) {
    *b1 =  word & 255;
    *b2 =  word & (255 << 8);
    *b3 =  word & (255 << 16);
    *b4 =  word & (255 << 24);
}   

int main() {
    int word;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    cin >> word;
    fun(word, &b1, &b2, &b3, &b4);
    cout << (int)b1 << endl;
    cout << (int)b2 << endl;
    cout << (int)b3 << endl;
    cout << (int)b4 << endl;
    return 0;
}
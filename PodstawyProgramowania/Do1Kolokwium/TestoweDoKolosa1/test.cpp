#include <iostream>
using namespace std;

int main() {
    unsigned char v;
    int n; 
    cin >> n;
    v = static_cast<unsigned char>(n);
    v += 2;
    cout << static_cast<int>(v) << endl;
    return 0;
}
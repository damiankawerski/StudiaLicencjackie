#include <iostream>
using namespace std;

bool triangle_possible(float a, float b, float c) {
    if(a + b > c && b + c > a && c + a > b) return true;
    else return false;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << triangle_possible(a, b, c) << endl;
    return 0;
}
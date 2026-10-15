#include <iostream>
using namespace std;

float add(float x, float y) {
    return x + y;
}

float subtract(float x, float y) {
    return x - y;
}

float multipy(float x, float y) {
    return x * y;
}

float divide(float x, float y) {
    return x/y;
}

int main() {
    float x,y;
    unsigned int z;
    cin >> x >> y >> z;
    float (*operations[4]) (float, float) = {add, subtract, multipy, divide};
    cout << operations[z] (x, y) << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int *wskInt;
    float *wskFloat;
    float n = 1;
    wskFloat = &n;
    wskInt = reinterpret_cast<int*>(wskFloat);
    cout << *wskInt << endl;
    return 0;
}
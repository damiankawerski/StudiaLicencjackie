#include <iostream>
using namespace std;

int zamiana(float a) {
    return 2 * a;
}
int main() {
    float a;
    cin >> a;
    cout << zamiana(a) << endl;
}
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int r;
    cin >> r;


    for(int y = -r ; y <= r ; y++) {
        for(int x = -r ; x <= r ; x++) {
            if(x*x + y*y <= pow(r, 2)) {
                cout << "#";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}

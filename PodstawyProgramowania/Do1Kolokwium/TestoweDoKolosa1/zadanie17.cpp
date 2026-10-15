#include <iostream>
#include <cmath>
using namespace std;

int fun(int n, float x[], float y[], float z[], float r, float personX, float personY) {
    for(int i = 0 ; i < n ; i++) {
        float distance = sqrt(pow(x[i] - personX, 2) + pow(y[i] - personY, 2) + pow(z[i], 2));
        if(distance < r) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n = 6;
    float x[n]={2,2,3,5,6,8};
    float y[n]={2,6,3,7,1,6};
    float z[n]={2,1,1.5,2,2,2};
    float r = 2.5;
    float personX = 7;
    float personY = 2;
    cout << fun(n, x, y, z, r, personX, personY) << endl;
    return 0;
}
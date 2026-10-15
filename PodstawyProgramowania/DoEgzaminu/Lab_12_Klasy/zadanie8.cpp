#include <iostream>
#include <cmath>
using namespace std;

class Complex {
public:
    double im, re;

    double abs() {
        return sqrt(pow(im, 2) + pow(re, 2));
    }
};

Complex add(Complex a, Complex b) {
    Complex result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}

int main() {
    Complex a;
    Complex b;
    a.im = 2;
    a.re = 2;
    b.im = 4;
    b.re = 4;
    Complex sum = add(a, b);
    cout << sum.re << " + i" << sum.im << endl;
    cout << a.abs() << endl;
    cout << b.abs() << endl;
    return 0;
}
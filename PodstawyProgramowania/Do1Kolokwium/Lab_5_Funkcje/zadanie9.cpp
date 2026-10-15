#include <iostream>
using namespace std;


void ref(float &a, float &b) {
  float temp = a;
  a = b;
  b = temp;
}
int main() {
    float a, b;
    cin >> a >> b;
    cout << "wartosc a i b przed : " << a << " " << b << endl; 
    ref(a, b);
    cout << "wartosc a i b po : " << a << " " << b << endl; 
    return 0;
    
}
 

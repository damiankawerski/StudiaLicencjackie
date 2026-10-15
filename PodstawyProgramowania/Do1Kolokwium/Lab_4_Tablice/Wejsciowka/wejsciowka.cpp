#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float rata = 0;
    double X;
    int M;
    cin >> X >> M;
    if(M <= 0) return 0;
    if(X < 0) return 0;
    double odsetki = 0;
    double rataBezOdsetek = X/M;
    int caloscSplacona = 0;
    for(int i = 0 ; i < M ; i++) {   
        odsetki = X*0.2f;
        rata = rataBezOdsetek + odsetki;
        X -= rata;
        cout << fixed << setprecision(2) << rata << endl;
        caloscSplacona += rata;
    }
    cout << fixed << setprecision(2) << caloscSplacona << endl;
    return 0;
}
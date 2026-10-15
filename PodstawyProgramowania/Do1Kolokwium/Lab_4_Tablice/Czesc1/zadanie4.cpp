#include <iostream>
#include <cmath>
using namespace std;
int main() {
    const int n = 4;
    float suma = 0;
    float srednia_arytmetyczna = 0;
    double srednia_geometryczna = 0;
    double srednia_harmoniczna = 0;
    double odchylenie_standardowe = 0;
    float arr[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    for(int i = 0 ; i < n ; i++) {
        suma += arr[i]; 
    }
    srednia_arytmetyczna = suma/n;
    double mnozenie = 1;
    for(int i = 0 ; i < n ; i++) {
        mnozenie = mnozenie * arr[i];
    }
    srednia_geometryczna = pow(mnozenie, (1/n));
    float suma_odwrotnosci = 0;
    for(int i = 0 ; i < n ; i++) {
        suma_odwrotnosci += suma_odwrotnosci + 1/arr[i];
    }
    srednia_harmoniczna = n/suma_odwrotnosci;
    cout << "suma: " << suma << endl;
    cout << "srednia arytmetyczna: " << srednia_arytmetyczna << endl;
    cout << "srednia geometryczna: " << srednia_geometryczna << endl;
    cout << "srednia harmoniczna: " << srednia_harmoniczna << endl;
    
    // SREDNIA GEOMETRYCZNA I HARMONICZNA NIE DZIALA 
    return 0;
}
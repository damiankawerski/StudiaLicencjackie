#include <iostream>
using namespace std;

double czesc_calkowita_i_ulamkowa(double &number) {
    int calkowita = static_cast<int>(number);
    number = number - calkowita;
    return calkowita;
    
}
int main() {
    double number;
    cin >> number;
    cout << czesc_calkowita_i_ulamkowa(number) << " " << number << endl;
    return 0;
}
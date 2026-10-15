#include <iostream>
using namespace std;

double czesc_ulamkowa(double number) {
    int calkowita = static_cast<int>(number);
    return number - calkowita;
}
int main() {
    double number;
    cin >> number;
    cout << czesc_ulamkowa(number) << endl;
    return 0;
}
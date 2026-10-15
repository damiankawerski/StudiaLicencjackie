#include <iostream>
using namespace std;

int funRekur(int year, float amount, int yearTime) {
    if(year == 0) return amount;
    else if(yearTime == 0) {
        return funRekur(year, amount * 1.5, yearTime + 1);
    }
    else if(yearTime == 1) {
        return funRekur(year, amount, yearTime + 1);  
    }
    else if(yearTime == 2) {
        return funRekur(year, amount - 10, yearTime + 1);  
    }
    else if(yearTime == 3) {
        return funRekur(year - 1, amount * 0.6  , 0); 
    }
    return 0;
}

int main() {
    int year, yearTime;
    float amount;
    cin >> year >> amount >> yearTime;
    cout << "Koncowy wynik: " << funRekur(year, amount, yearTime) << endl;
    return 0;
}
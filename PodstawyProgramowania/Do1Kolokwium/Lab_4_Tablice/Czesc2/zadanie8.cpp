#include <iostream>
using namespace std;

int main() {
    char napis[100];
    cin.getline(napis, 100);
    int wartoscZamiany = 'a' - 'A';
    cout << wartoscZamiany << endl;
    int index = 0;
    while(napis[index] != '\0') {
        if(napis[index] >= 'a' && napis[index] <= 'z') {
            napis[index] = napis[index] - wartoscZamiany;
        }
        else if(napis[index] >= 'A' && napis[index] <='Z') {
            napis[index] = napis[index] + wartoscZamiany;
        }
        index++;
    }
    cout << napis << endl;
    return 0;
}
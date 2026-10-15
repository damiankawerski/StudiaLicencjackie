#include <iostream> 
using namespace std;

int main() {
    int wartoscZamiany = 'a' - 'A';
    char napis[100];
    cin.getline(napis, 100);
    int index = 0;
    if(napis[index] >= 'a' && napis[index] <= 'z') napis[index] = napis[index] - wartoscZamiany;
    while(napis[index] != '\0') {
       if(napis[index] == ' ') {
            napis[index + 1] = napis[index + 1] - wartoscZamiany;
       }
       index++;
    }
    cout << napis << endl;
    return 0;
}

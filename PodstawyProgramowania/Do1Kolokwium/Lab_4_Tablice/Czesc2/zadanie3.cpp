#include <iostream>
using namespace std;
int main() {
    int counter = 0;
    char napis[100];
    cin.getline(napis, 100);
    char kopia[100];
    while(napis[counter] != '\0') {
        kopia[counter] = napis[counter];
        counter++;
    }
    kopia[counter] = '\0';
    cout << kopia << endl;

}
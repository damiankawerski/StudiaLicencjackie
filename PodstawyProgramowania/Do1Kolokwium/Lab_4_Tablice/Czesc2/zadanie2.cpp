#include <iostream>
using namespace std;
int main() {
    int lenght = 0;
    char napis[100];
    cin.getline(napis, 100); 
    while (napis[lenght] != '\0') lenght++;
    cout << lenght << endl;
    return 0;
}
#include <iostream> 
using namespace std;

int main() {
    char napis[100];
    cin.getline(napis, 100);
    int index = 0;
    while(napis[index] != '\0') {
        cout << napis[index];
        if(napis[index] == ' ') cout << endl;
        index++;
    }
    cout << endl;
    return 0;
}
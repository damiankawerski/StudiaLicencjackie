#include <iostream>
using namespace std;

int main() {
    char napis1[100];
    char napis2[100];

    cin.getline(napis1, 100);
    
    cin.getline(napis2, 100);

    int i = 0;

    while(napis1[i] != '\0' && napis2[i] != '\0') {
        if(napis1[i] != napis2[i]) {
            if(napis1[i] < napis2[i]) {
                cout << -1 << endl;
                return 0;
            }
            else {
                cout << 1 << endl;
                return 0;
            }
        }    
        i++;
    }
    if(napis1[i] == '\0' && napis2[i] == '\0') cout << 0 << endl;
    else if(napis1[i] == '\0') cout << -1 << endl;
    else cout << 1 << endl;
    return 0;
}

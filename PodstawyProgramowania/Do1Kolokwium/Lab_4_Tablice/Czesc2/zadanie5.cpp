#include <iostream>
using namespace std;
int main() {
    char znak;
    cin >> znak;
    cin.ignore();
    char string[100];
    cin.getline(string, 100);
    
    for(int i = 0 ; string[i] != '\0'; i++ ) {
        if(string[i] == znak) {
            cout << znak << " jest na miejscu " << i << endl;
        }
    }
    

return 0;
}
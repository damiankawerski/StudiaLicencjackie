#include <iostream>
using namespace std;


bool fun(char str[]) {

    for(int i = 0 ; str[i] != '\0' ; i++) {
        if((str[i] < 'a' || str[i] > 'z')) {
            return false;
        }
    }
    return true;
}


int main() {
    char str[100];
    cin.getline(str, 100);
    cout << fun(str) << endl;
    return 0;
}
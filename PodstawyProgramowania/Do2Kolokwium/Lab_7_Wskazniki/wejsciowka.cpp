#include <iostream>
using namespace std;

int countFun(char str[]) {
    int counter = 0;
    while(str[counter] != '\0') {
        counter++;
    }
    return counter;
}

bool fun(char str[]) {
    int count = 0;
    for(int i = 0 ; i < countFun(str) ; i++) {
        if((str[i] >= 'a' && str[i] <= 'z')) {
            count++;
        }
    }
    if(count == countFun(str)) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    char str[100];
    cin.getline(str, 100);
    cout << fun(str) << endl;
    return 0;
}
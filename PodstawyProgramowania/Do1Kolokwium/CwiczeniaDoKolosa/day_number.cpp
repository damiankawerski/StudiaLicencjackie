#include <iostream>
using namespace std;

bool compare(const char string1[],const char string2[]) {
    int i = 0;
    while(string1[i] != '\0' && string2[i] != '\0' && string1[i] == string2[i]){
        
        i++;
    }
    return string1[i] == string2[i];
}

int day_number(char string[]) {
    char dayOfWeek[7][13] = {"poniedzialek", "wtorek", "sroda", "czwartek", "piatek", "sobota", "niedziela"};
    for(int i = 0 ; i < 7 ; i++) {
        if(compare(string, dayOfWeek[i])) return i;
    }
    return -1;
}

int main() {
    char userInput[13];
    cin.getline(userInput, 13);

    cout << day_number(userInput) << endl;
    return 0;
}
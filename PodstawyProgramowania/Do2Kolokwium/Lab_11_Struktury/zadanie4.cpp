#include <iostream>
using namespace std;

const char* find_substring(const char* napis, const char* podnapis) {
    for(int i = 0 ; napis[i] != '\0' ; i++) {
        int j = 0 ;
        while(podnapis[j] != '\0' && napis[i + j] != '\0' && podnapis[j] == napis[i + j]) {
            j++;
        }
        if(podnapis[j] == '\0') {
            return &napis[i];
        }
    }
    return nullptr;
}

int main() {
    const char* napis = "Hello World";
    const char* podnapis = "World";
    char first_sign = *(find_substring(napis, podnapis));
    cout << first_sign << endl;
    return 0; 
}
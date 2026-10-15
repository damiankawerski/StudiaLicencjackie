#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// %26 bo alfabet ma 26 znakow

void generateRandomWords(int n, int m) {
    srand(time(0));
    for(int i = 0 ; i < n ; i++) {
        int randomizedLenght = rand() % m + 1;
        for(int j = 0 ; j < randomizedLenght ; j++) {
            char randomChar = rand() % 2 == 0 ? 'a' + rand() % 26 : 'A' + rand() % 26;
            cout << randomChar;
        }
        cout << " ";
    }
    cout << endl;
}

int main() {
    unsigned int n, m;
    cin >> n >> m;
    generateRandomWords(n, m);
    return 0;
}
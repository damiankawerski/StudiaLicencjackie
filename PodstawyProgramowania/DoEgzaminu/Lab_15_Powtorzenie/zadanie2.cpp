#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string words_to_count = "pierwsze drugie trzecie czwarte piate szoste";
    string slowo;
    istringstream ss(words_to_count);
    int counter = 0;
    while(ss >> slowo) {
        counter++;
    }

    cout << counter << endl;
    return 0;
}

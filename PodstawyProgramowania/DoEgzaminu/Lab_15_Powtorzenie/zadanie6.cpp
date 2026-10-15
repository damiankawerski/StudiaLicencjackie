#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    fstream file;
    file.open("zadanie6.txt");

    if(!file.is_open()) {
        return -1;
    }

    const int maxWords = 100;
    string* searchedWords = new string[maxWords];
    int counter = 0;
    string line;
    while(getline(file, line) && counter < maxWords) {
        size_t pos = 0;
            while((pos = line.find("any", pos)) != string::npos) {
                size_t wordStart = line.rfind(' ', pos);
                size_t wordEnd = line.find(' ', pos);
                if(wordStart == string::npos) {
                    wordStart = 0;
                } else {
                    wordStart++;
                }
                if(wordEnd == string::npos) {
                    wordEnd = line.length();
                }
                string word = line.substr(wordStart, wordEnd - wordStart);
                searchedWords[counter] = word;
                counter++;
                pos = wordEnd;
            }
    }

    for(int i = 0 ; i < counter ; i++) {
        cout << searchedWords[i] << endl;
    }

    delete[] searchedWords;
    file.close();
    return 0;
}
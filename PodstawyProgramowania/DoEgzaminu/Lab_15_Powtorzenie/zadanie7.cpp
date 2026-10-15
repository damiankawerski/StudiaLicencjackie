#include <iostream>
#include <sstream>
using namespace std;

string atBashEncrypt(const string& text) {
    stringstream codedText;
    for(char x : text) {
        if(isalpha(x)) {
            char base = isupper(x) ? 'A' : 'a';
            codedText << static_cast<char>(base + 'Z' - x + 'A');
        }
    }
    return codedText.str();
}

string atBashDecode(string& text) {
    return atBashEncrypt(text);
}

int main() {
    string str = "ala ma kota";
    atBashEncrypt(&str);
    cout << str << endl;
    return 0;
}
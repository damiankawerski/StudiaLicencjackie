#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    fstream file;
    file.open("zadanie1.cpp");
    if(!file.is_open()) {
        return -1;
    }
    string temp;
    while(getline(file, temp)) {
        cout << temp << endl;
    }

    file.close();
    return 0;
}
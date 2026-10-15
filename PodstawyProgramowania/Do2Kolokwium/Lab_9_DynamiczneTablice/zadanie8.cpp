#include <iostream>
#include <cstring>
using namespace std;

char fun()

int main() {
    char *napis = new char[100];
    char *szukany = new char[100];
    delete[] napis;
    delete[] szukany;
    return 0;
}
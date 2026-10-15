#include <iostream>
#include <cstring>

void reverseString(char* &napis, size_t size) {
    char *kopia = new char[size];
    size_t index = size -1;
    for(size_t i = 0 ; i < size ; i++) {
        *(kopia + index) = *(napis + i);
        index--;
    }
    delete[] napis;
    napis = kopia;
}

int main() {
    char *napis = new char[100];
    std::cin.getline(napis, 100);
    reverseString(napis, std::strlen(napis));
    std::cout << napis << std::endl;
    delete[] napis;
    return 0;
}
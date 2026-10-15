#include <iostream>
#include <algorithm>
#include <cstring>

bool do_or_not(char x) {
    return std::islower(x);
}

int main() {
    char napis[100];
    char kopia[100];
    std::cin.getline(napis, 100);
    std::fill(kopia, kopia + strlen(napis), '-');
    std::copy_if(napis, napis + strlen(napis), kopia, do_or_not);
    std::cout << kopia << std::endl;
    return 0;
}
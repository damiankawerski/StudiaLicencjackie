#include <iostream>
#include <cstring>
using namespace std;

int compareWithVowels(const char* str) {
    const char* vowels= "aeiouAEIOU";
    return strpbrk(str, vowels) != nullptr;
}

const char* search_string(const char** string_array, int size, int (*pf)(const char*)) {
    const char* maxString = nullptr;
    int max_value = 0;
    for(int i = 0 ; i < size ; i++) {
        int value = pf(string_array[i]);
        if(max_value < value) {
            max_value = value;
            maxString = string_array[i];
        }
    }
    return maxString;
}


int main() {
    int size = 4;
    const char** napis = new const char*[size];
    napis[0] = "kiwi";
    napis[1] = "banana";
    napis[2] = "orange";
    napis[3] = "apple";
    const char* result = search_string(napis, size, compareWithVowels);
    if (result != nullptr) {
        std::cout << "Największa wartość funkcji porównującej dla napisu: " << result << std::endl;
    } else {
        std::cout << "Brak napisu spełniającego warunek funkcji porównującej." << std::endl;
    }
   
    delete[] napis;
    return 0;
}
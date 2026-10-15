#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class String {
private:
    char* string;
public:
    String() : string(nullptr) {}
    ~String() {
        delete[] string;
    }

    void resize(int new_size) {
        char* new_string = new char[new_size];
        strcpy(new_string, string);
        delete[] string;
        string = new_string;
    }

    void changeStars(char* word, const char* token) {
        char* ptr = strstr(string, token);

        while(ptr != nullptr) {
            size_t word_len = strlen(word);
            size_t token_len = strlen(token);

            if(word_len > token_len) {
                resize(strlen(string) + word_len - token_len);
                memmove(ptr + word_len, )
            }
        }
    }
};

int main() {

}
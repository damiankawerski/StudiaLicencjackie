#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char *string;
public:
    String() : string(nullptr) {}

    String(const char *string) {
       this->string = new char[strlen(string + 1)];
       strcpy(this->string, string);
    }

    String(String &string) {
        this->string = new char[strlen(string.string + 1)];
        strcpy(this->string, string.string);
    }

    String& operator=(const String& t) {
        this->~String();
        this->string = new char[strlen(t.string + 1)];
        strcpy(this->string, string);
        return *this;
    }

    ~String() {
        delete[] string;
    }

    size_t length() {
        return strlen(string);
    }

    const char* cstring() const {
        return string;
    }

    void append(const char* s) {
        char* newStr = new char[length() + strlen(s + 1)];
        strcpy(newStr, string);
        strcat(newStr, s);
        delete[] string;
        string = newStr;
    }

    void clear() {
        delete[] string;
        string = nullptr;
    }

    bool empty() {
        if(string == nullptr || length() == 0) return true;
        return false;
    }

    void print() {
        cout << cstring() << endl;
    }

};


int main() {
    String s1("Hello");
    String s2(s1);
    String s3 = s1;


    s1.append(s2.cstring());
    s1.print();
    

 
    return 0;
}
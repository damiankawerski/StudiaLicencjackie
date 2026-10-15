//names zle działa w funkcji fun napraw

#include <iostream>
#include <cstring>
using namespace std;

bool compare_str(char *str1, char *str2) {
    if(str1 == nullptr || str2 == nullptr) {
        return false;
    }
    return strcmp(str1, str2) == 0;
}

void fun(char **input, char **output, int &size) {
    char delim = ' ';
    char space[] = " ";

    char **names = new char*[size];
    for (int i = 0; i < size; i++) {
        names[i] = new char[12];
    }
    
    for(int i = 0 ; i < size ; i++) {
        char* token = strtok(input[i], &delim);
        strcpy(names[i], token);

        
         strcat(output[i], token);
        
        for(int j =  0 ; j < size ; j++) {

            if(compare_str(names[j], token)) {
                strcat(output[j], space);
                token = strtok(nullptr, &delim);
                strcat(output[j], token);
            }
        }
    }

    for(int i = 0 ; i < 4 ; i++) {
            delete[] names[i];
    }
    delete[] names;
}

void show_array(char **arr, int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << endl;
    };
}

int main() {
    const char* tablice[] = {
        "LRY 1234",
        "LU 87654",
        "WA 1234",
        "LRY 888",
        "LU 999"
    };

    int size = sizeof(tablice) /  sizeof(tablice[0]);

    char **input = new char*[size];
    for(int i = 0 ; i < 5 ; i++) {
        input[i] = new char[12];
        strcpy(input[i], tablice[i]);

    }
    char **output = new char*[size];
    for(int i = 0 ; i < size ; i++) {
        output[i] = new char[30];
    }

    fun(input, output, size);
    show_array(output, size);

    for(int i = 0 ; i < size ; i++) {
        delete[] input[i];
    }
    delete[] input;
    for(int i = 0 ; i < size ; i++) {
        delete[] output[i];
    }
    delete[] output;
    return 0;
}
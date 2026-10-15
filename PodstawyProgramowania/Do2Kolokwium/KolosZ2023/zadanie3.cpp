#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

void random_generate(char **arr, int n, int max_len, int min_len) {
    srand(time(0));
    for(int i = 0 ; i < n ; i++) {
        int j_value = rand() % (max_len - min_len + 1) + min_len;
        for(int j = 0 ; j < j_value ; j++) {
            arr[i][j] = 'a' + rand() % ('z' - 'a' + 1);
        }
        arr[i][j_value] = '\0';
    }
}

void sort_strings(char **arr, int n) {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(strcmp(arr[i], arr[j]) > 0 ) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void show_strings(char **arr, int n) {
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    unsigned int n, min_len, max_len;
    cin >> n >> min_len >> max_len;
    char **strings = new char*[n];
    for(int i = 0 ; i < n ; i++) {
        strings[i] = new char[max_len + 1];
    }
    random_generate(strings, n, max_len, min_len);
    sort_strings(strings, n);
    show_strings(strings, n);


    for(int i = 0 ; i < n ; i++) {
        delete[] strings[i];
    }
    delete[] strings;
    return 0;
}



/* <3,5> -> rand() % 3 + 3  */
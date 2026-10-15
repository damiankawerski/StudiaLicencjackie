#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


void best_productions(char** records, char** result, int size) {
    int sort_arr[size];
    for(int i = 0 ; i < size ; i++) {
        char *token = strtok(records[i], "/");
        sort_arr[i] = atoi(token);
        token = strtok(nullptr, "/");
        strcpy(result[i], token);
    }

    for(int i = 0 ; i < size ; i++) {
        for(int j = 0 ; j < size - 1 ; j++) {
            if(sort_arr[i] > sort_arr[j]) {
                swap(sort_arr[i], sort_arr[j]);
                swap(result[i], result[j]);
            }
        }
    }
}

void show(char** records, int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << records[i] << endl;
    }
}

int main() {
    int size = 5;
    char **arr = new char*[size];
    arr[0] = new char[100] {"12000000/Pingwiny_z_Madagaskaru"};
    arr[1] = new char[100] {"540000000/Lupin"};
    arr[2] = new char[100] {"191000000/House_of_Cards"};
    arr[3] = new char[100] {"2000000/Nic_smiesznego"};
    arr[4] = new char[100] {"10000000/Shrek"};

    char **results = new char*[size];
    for(int i = 0 ; i < size ; i++) {
        results[i] = new char[100];
    }


    best_productions(arr, results, size);
    show(results, size);


    for(int i = 0 ; i < size - 1 ; i++) {
        delete[] results[i];
    }
    delete[] results;
    for(int i = 0 ; i < size ; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
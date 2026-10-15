#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    FILE* file = fopen("zadanie2.txt", "a");

    for(int i = 0; i < 10; i++){
        fprintf(file, "%d ", i);
    }

    fclose(file);  
}
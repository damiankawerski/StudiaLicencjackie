#include <cstdio>
using namespace std;

int count(char* plik) {
    FILE* file = fopen(plik, "r");
    int counter = 0;
    int x;
    while(fscanf(file, "%d", &x) != EOF) {
        counter++;
    }
    fclose(file);
    return counter;
}

void increase(char* plik) {
    int size = count(plik);
    FILE* file = fopen(plik, "r");
    int x;
    int* arr = new int[size];
    int k = 0;
    while(fscanf(file, "%d", &x) != EOF){
        arr[k] = ++x;
        k++;
    }
    fclose(file);

    file = fopen(plik, "w");
    for(int i = 0 ; i < size ; i++) {
        fprintf(file, "%d ", arr[i]); 
    }
    delete[] arr;
    fclose(file);
}

int main() {
    char plik[30] = "zadanie2.txt";
    increase(plik);
    return 0;
}
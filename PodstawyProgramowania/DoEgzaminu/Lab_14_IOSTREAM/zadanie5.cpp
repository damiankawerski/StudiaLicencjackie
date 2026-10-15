#include <iostream>
using namespace std;

void write_array(char *plik, float *arr, int size) {
    FILE* file = fopen(plik, "wb");

    if(!file) {
        return;
    }

    fwrite(arr, sizeof(float), size, file);
    fclose(file);
}

int read_array(char *plik, float *arr, int size) {
    FILE* file = fopen(plik, "rb");
    int counter = fread(arr, sizeof(float), size, file);
    fclose(file);
    return counter;
}

int main() {
    int size = 9;
    float arr[9] = {1, 2, 3, 4, 5, 6 ,7 ,8 ,9};
    char sciezka[30] = "zadanie5.bin";
    write_array(sciezka, arr, size);
    read_array(sciezka, arr, size);
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
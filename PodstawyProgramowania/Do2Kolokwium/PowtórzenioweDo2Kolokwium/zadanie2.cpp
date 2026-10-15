#include <iostream>
using namespace std;


void* fun(void **wsk, unsigned int N, size_t bytes, int x, int y) {
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N - i ; j++) {
            if(i == y && j == x) {
                return static_cast<char*>(wsk[i]) + j * bytes;
            }
        }
    }
    return nullptr;
}

void fill_arr_triangle(void** arr, unsigned int N, size_t size) {
    int value = 0;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N - i ; j++) {
            *reinterpret_cast<int*>(static_cast<char*>(arr[i]) + j * size) = value++;
        }
    }
}

void show_arr_triangle(void** arr, unsigned int N, size_t size) {
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N - i ; j++) {
            cout << *reinterpret_cast<int*>(static_cast<char*>(arr[i]) + j * size) << " ";
        }
        cout << endl;
    }
}

int main() {
    unsigned int N = 5;
    int x = 2;
    int y = 1;
    size_t size = sizeof(int);


    void **array = new void*[N];
    for(int i = 0 ; i < N ; i++) {
        array[i] = new char[(N - i) * size];
    }

    fill_arr_triangle(array, N, size);
    show_arr_triangle(array, N, size);

    cout << endl << endl << endl;
    
    int* result = reinterpret_cast<int*>(fun(array, N, size, x, y));

    if(result != nullptr) {
        cout << "Element to: " << *result << endl;
    }
    else {
        cout << "brak elementu" << endl;
    }

    
    for(int i = 0 ; i < N ; i++) {
        delete[] static_cast<char*>(array[i]);
    }
    delete[] array;
    return 0;
}
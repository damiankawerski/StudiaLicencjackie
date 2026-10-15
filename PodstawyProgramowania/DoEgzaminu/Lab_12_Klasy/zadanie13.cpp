#include <iostream>
using namespace std;

enum typy{
    CHAR,
    UCHAR,
    INT,
    FLOAT,
};

double fun(void* arr, int size, typy var) {
    double suma = 0.0;

    switch(var) {
        case CHAR: {
            char* wsk = static_cast<char*>(arr);
            for(size_t i = 0 ; i < size ; i++) {
                suma += static_cast<double>(wsk[i]);
            }
            break;
        }
        case UCHAR: {
            unsigned char* wsk = static_cast<unsigned char*>(arr);
            for(size_t i = 0 ; i < size ; i++) {
                suma += static_cast<double>(wsk[i]);
            }
            break;
        }
        case INT: {
            int* wsk = static_cast<int*>(arr);
            for(size_t i = 0 ; i < size ; i++) {
                suma += static_cast<double>(wsk[i]);
            }
            break;
        }
        case FLOAT: {
            float* wsk = static_cast<float*>(arr);
            for(size_t i = 0 ; i < size ; i++) {
                suma += static_cast<double>(wsk[i]);
            }
            break;
        }
    }
    return suma / static_cast<double>(size);
}

int main() {
    int tablicaInt[] = {1, 2, 3, 4, 5};
    double sredniaInt = fun(tablicaInt, sizeof(tablicaInt) / sizeof(int), INT);
    std::cout << "Średnia arytmetyczna dla typu INT: " << sredniaInt << std::endl;

    float tablicaFloat[] = {1.5f, 2.5f, 3.5f, 4.5f, 5.5f};
    double sredniaFloat = fun(tablicaFloat, sizeof(tablicaFloat) / sizeof(float), FLOAT);
    std::cout << "Średnia arytmetyczna dla typu FLOAT: " << sredniaFloat << std::endl;

    // Możesz dodać przykłady dla innych typów danych

    return 0;
}
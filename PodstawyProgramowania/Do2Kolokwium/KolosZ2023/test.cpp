#include <iostream>
#include <cstring> // Dla funkcji memcmp() i memset()

// Funkcja null_set()
void null_set(void* arr1, void* arr2, size_t count, size_t element_size) {
    // Porównaj każdy element i zeruj, jeśli są identyczne
    for (size_t i = 0; i < count; ++i) {
        if (std::memcmp(static_cast<char*>(arr1) + i * element_size,
                        static_cast<char*>(arr2) + i * element_size,
                        element_size) == 0) {
            std::memset(static_cast<char*>(arr1) + i * element_size, 0, element_size);
            std::memset(static_cast<char*>(arr2) + i * element_size, 0, element_size);
        }
    }
}

int main() {
    // Przykładowe tablice
    int intArray1[] = {1, 2, 3, 4, 5};
    int intArray2[] = {1, 6, 3, 4, 5};
    size_t size = sizeof(intArray1) / sizeof(intArray1[0]);

    // Wywołanie funkcji null_set() dla tablic int
    null_set(intArray1, intArray2, size, sizeof(intArray1[0]));

    // Wyświetlenie zawartości tablic
    std::cout << "Tablica 1 po null_set(): ";
    for (size_t i = 0; i < size; ++i) {
        std::cout << intArray1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Tablica 2 po null_set(): ";
    for (size_t i = 0; i < size; ++i) {
        std::cout << intArray2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

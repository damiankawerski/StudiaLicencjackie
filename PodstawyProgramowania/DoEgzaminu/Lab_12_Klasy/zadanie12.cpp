#include <iostream>

class Vector {
private:
    int* array;
    int currentSize;
    int capacity;

public:
    // Konstruktor
    Vector() : array(nullptr), currentSize(0), capacity(0) {}

    // Destruktor
    ~Vector() {
        clear();
    }

    // Metoda inicjująca elementy składowe obiektu
    void init() {
        clear();
    }

    // Metoda zwracająca referencję na i-ty element tablicy
    int& at(int i) {
        if (i < 0 || i >= currentSize) {
            std::cerr << "Index out of bounds!" << std::endl;
            exit(1); // Można również obsłużyć tę sytuację inaczej, np. rzucając wyjątkiem
        }
        return array[i];
    }

    // Metoda dodająca element na koniec tablicy
    void append(int v) {
        if (currentSize == capacity) {
            resize(capacity * 2 + 1); // Podwajamy pojemność, ale minimum 1
        }
        array[currentSize++] = v;
    }

    // Metoda zmieniająca rozmiar tablicy na nowy, zachowując elementy już dodane do tablicy
    void resize(int size) {
        int* newArray = new int[size];
        for (int i = 0; i < currentSize; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = size;
    }

    // Metoda zwracająca rozmiar tablicy
    int size() const {
        return currentSize;
    }

    // Metoda czyszcząca całą zawartość obiektu
    void clear() {
        delete[] array;
        array = nullptr;
        currentSize = 0;
        capacity = 0;
    }
};

int main() {
    Vector vec;
    
    // Testowanie metody append
    vec.append(10);
    vec.append(20);
    vec.append(30);

    // Testowanie metody at
    std::cout << "Element at index 1: " << vec.at(1) << std::endl;

    // Testowanie metody size
    std::cout << "Vector size: " << vec.size() << std::endl;

    // Testowanie metody resize
    vec.resize(5);

    // Testowanie metody clear
    vec.clear();
    std::cout << "Vector size after clear: " << vec.size() << std::endl;

    return 0;
}

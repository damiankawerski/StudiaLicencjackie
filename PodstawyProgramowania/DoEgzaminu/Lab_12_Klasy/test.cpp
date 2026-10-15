#include <iostream>

class Vector {
private:
    int* array;  // Wskaźnik do dynamicznej tablicy
    int currentSize;  // Aktualny rozmiar tablicy
    int capacity;  // Pojemność tablicy (rozmiar zaalokowanej pamięci)

public:
    // Konstruktor
    Vector() : array(nullptr), currentSize(0), capacity(0) {}

    // Destruktor
    ~Vector() {
        clear();
    }

    // Metoda inicjująca elementy składowe obiektu
    void init() {
        clear();  // Upewniamy się, że stara zawartość zostaje usunięta

        // Inicjowanie tablicy indeksami
        for (int i = 0; i < capacity; i++) {
            append(i);
        }
    }

    // Metoda zwracająca referencję na i-ty element tablicy
    int& at(int i) {
        if (i < 0 || i >= currentSize) {
            std::cerr << "Index out of bounds!" << std::endl;
            exit(1);  // Przerwanie programu w przypadku błędnego indeksu
        }
        return array[i];
    }

    // Metoda dodająca element na koniec tablicy
    void append(int v) {
        if (currentSize == capacity) {
            // Tablica jest pełna, potrzebujemy zwiększyć jej rozmiar
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;  // Podwajamy pojemność (lub ustawiamy na 1, jeśli tablica była pusta)
            resize(newCapacity);
        }

        array[currentSize] = v;
        currentSize++;
    }

    // Metoda zmieniająca rozmiar tablicy na nowy, zachowując elementy już dodane do tablicy
    void resize(int newSize) {
        int* newArray = new int[newSize];

        // Przenoszenie istniejących elementów do nowej tablicy
        for (int i = 0; i < currentSize; i++) {
            newArray[i] = array[i];
        }

        delete[] array;  // Zwolnienie starej tablicy

        array = newArray;
        capacity = newSize;
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
    // Przykładowe użycie klasy Vector
    Vector myVector;

    myVector.init();

    // Wypisanie zawartości tablicy po inicjalizacji
    std::cout << "Vector after initialization:" << std::endl;
    for (int i = 0; i < myVector.size(); i++) {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    // Modyfikacja i wypisanie zawartości tablicy
    myVector.at(1) = 100;
    std::cout << "Vector after modifying element at index 1:" << std::endl;
    for (int i = 0; i < myVector.size(); i++) {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    // Czyszczenie tablicy
    myVector.clear();

    return 0;
}

#include <iostream>

// Deklaracja funkcji mnożącej macierze 3x3
void multiplyMatrices(const float* matrix1, const float* matrix2, float* result);

int main() {
    // Przykładowe macierze 3x3
    float matrix1[9] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    float matrix2[9] = {9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
    float result[9];

    // Wywołanie funkcji mnożącej macierze
    multiplyMatrices(matrix1, matrix2, result);

    // Wyświetlenie wyniku
    std::cout << "Wynik mnożenia macierzy:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << *(result + i * 3 + j) << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}

// Implementacja funkcji mnożącej macierze 3x3
void multiplyMatrices(const float* matrix1, const float* matrix2, float* result) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // Inicjalizacja elementu result[i][j]
            float sum = 0.0;
            for (int k = 0; k < 3; ++k) {
                sum += *(matrix1 + i * 3 + k) * *(matrix2 + k * 3 + j);
            }
            *(result + i * 3 + j) = sum;
        }
    }
}

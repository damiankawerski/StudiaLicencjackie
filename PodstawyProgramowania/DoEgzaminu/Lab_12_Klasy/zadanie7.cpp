#include <iostream>
#include <cstdlib>
#include <ctime>

class Identifier {
public:
    Identifier() {
        // Inicjalizacja generatora liczb pseudolosowych na podstawie aktualnego czasu
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        // Ustawienie początkowej wartości identyfikatora
        id_ = generateId();
    }

    // Publiczna metoda zwracająca identyfikator
    unsigned int id() {
        return id_++;
    }

private:
    // Prywatna metoda do generowania identyfikatora
    unsigned int generateId() {
        // Generowanie losowej liczby całkowitej
        return std::rand();
    }

    // Prywatne pole przechowujące aktualną wartość identyfikatora
    unsigned int id_;
};

int main() {
    
    Identifier obj;

   
    std::cout << "Id: " << obj.id() << std::endl;
    std::cout << "Id: " << obj.id() << std::endl;
    std::cout << "Id: " << obj.id() << std::endl;

    return 0;
}

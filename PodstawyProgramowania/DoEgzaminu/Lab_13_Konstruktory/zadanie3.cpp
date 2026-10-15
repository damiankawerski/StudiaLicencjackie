#include <iostream>
#include <cstring>
using namespace std;

enum AnimalType {
    KOT,
    PIES,
    RYBKA,
    HOMIK,
};

class Animal {
private:
    AnimalType animal;
    char name[11];
public:
    Animal(AnimalType animaltype, const char* NAME) : animal(animaltype), name("unnamed") {
        strncpy(name, NAME, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
    }

    Animal(const Animal& other) : animal(other.animal) {
        strncpy(name, other.name, sizeof(name));
    }

    ~Animal() {};
    void say_something(int n) {
        for(int i = 0 ; i < n ; i++) {
            switch(animal) {
                case KOT:
                cout << "miał" << endl;
                break;
                case PIES:
                cout << "hał" << endl;
                break;
                case RYBKA:
                cout << "bul bul" << endl;
                break;
                case HOMIK:
                cout << "szur szur" << endl;
                break;
                default:
                cout << "szeroko ręce i wysoko nogi" << endl;
                break;
            }
        }
    }
};

int main() {
    Animal dog(AnimalType::PIES, "wsiuras");
    Animal cat(AnimalType::KOT, "siersiuch");

    dog.say_something(3);
    cat.say_something(2);
    Animal copiedCat = cat;
    copiedCat.say_something(2);
    return 0;
}
#include <iostream>
#include <string>
#include <memory>

class CharacterMemento {
    std::string name;
    int health;
    int mana;

public:
    CharacterMemento(const std::string& n, int h, int m)
        : name(n), health(h), mana(m) {}

    friend class GameCharacter;
};

class GameCharacter {
    std::string name;
    int health;
    int mana;

public:
    GameCharacter(const std::string& n, int h, int m)
        : name(n), health(h), mana(m) {}

    void printStatus() const {
        std::cout << "Postać: " << name
                  << " | HP: " << health
                  << " | Mana: " << mana << "\n";
    }

    std::unique_ptr<CharacterMemento> createMemento() const {
        return std::make_unique<CharacterMemento>(name, health, mana);
    }

    void restoreMemento(const CharacterMemento* memento) {
        if (memento) {
            name = memento->name;
            health = memento->health;
            mana = memento->mana;
        }
    }

    void takeDamage(int dmg) { health -= dmg; }
    void useMana(int cost) { mana -= cost; }
};

int main() {
    GameCharacter hero("Zgred", 100, 50);

    hero.printStatus();

    std::unique_ptr<CharacterMemento> save1 = hero.createMemento();

    hero.takeDamage(40);
    hero.useMana(30);
    hero.printStatus();

    hero.restoreMemento(save1.get());
    hero.printStatus();

    return 0;
}

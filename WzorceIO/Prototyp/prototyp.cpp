#include <iostream>
#include <memory>
using namespace std;

class Monster {
    string type;
    int hp;

public:
    Monster(const string& t, int h) : type(t), hp(h) {}

    std::unique_ptr<Monster> clone() const {
        return make_unique<Monster>(*this);
    }

    void do_smth() const {
        cout << "Jestem potworem typu " << type << " z " << hp << " HP!\n";
    }
};


int main() {
    auto ork = new Monster("Ork", 100);

    auto orkClone = ork->clone();

    orkClone->do_smth();
    ork->do_smth();



    return 0;
}

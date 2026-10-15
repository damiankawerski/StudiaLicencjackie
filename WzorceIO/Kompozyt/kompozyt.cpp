#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;


class MenuComponent {
public:
    virtual void show() const = 0;
    virtual double getPrice() const = 0;
    virtual ~MenuComponent() = default;
};


class MenuItem : public MenuComponent {
    std::string name;
    double price;

public:
    MenuItem(const std::string& name, double price) : name(name), price(price) {}

    void show() const override {
        cout << std::string(0, ' ') << "- " << name << ": " << price << " zł\n";
    }

    double getPrice() const override {
        return price;
    }
};


class Menu : public MenuComponent {
    string name;
    std::vector<std::shared_ptr<MenuComponent>> items;

public:
    Menu(const std::string& name) : name(name) {}

    void add(const std::shared_ptr<MenuComponent>& item) {
        items.push_back(item);
    }

    void show() const override {
        std::cout << std::string(0, ' ') << name << ":\n";
        for (const auto& item : items) {
            item->show();
        }
    }

    double getPrice() const override {
        double total = 0;
        for (const auto& item : items) {
            total += item->getPrice();
        }
        return total;
    }


};


int main() {
    auto frytki = std::make_shared<MenuItem>("Frytki", 6.5);
    auto burger = std::make_shared<MenuItem>("Burger", 14.0);
    auto cola = std::make_shared<MenuItem>("Cola", 5.0);

    auto zestaw = std::make_shared<Menu>("Zestaw obiadowy");
    zestaw->add(burger);
    zestaw->add(frytki);
    zestaw->add(cola);

    auto menuGlowne = std::make_shared<Menu>("Menu Główne");
    menuGlowne->add(zestaw);
    menuGlowne->add(std::make_shared<MenuItem>("Lody", 7.0));

    menuGlowne->show();
    std::cout << "\nCena całkowita: " << menuGlowne->getPrice() << " zł\n";
}
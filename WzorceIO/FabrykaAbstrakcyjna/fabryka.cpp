#include <iostream>
using namespace std;

class Pizza {
public:
    virtual void prepare() = 0;
    virtual ~Pizza() = default;
};

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

class ItalianPizza : public Pizza {
public:
    void prepare() override {
        cout << "Przygotowuję włoską pizzę.\n";
    }
};


class ItalianBurger : public Burger {
public:
    void prepare() override {
        cout << "Przygotowuję włoskiego burgera.\n";
    }
};

class AmericanPizza : public Pizza {
public:
    void prepare() override {
        cout << "Przygotowuję amerykańską pizzę.\n";
    }
};

class AmericanBurger : public Burger {
public:
    void prepare() override {
        cout << "Przygotowuję tłustego amerykańskiego burgera.\n";
    }
};

class RestaurantFactory {
public:
    virtual Pizza* createPizza() = 0;
    virtual Burger* createBurger() = 0;
    virtual ~RestaurantFactory() = default;
};

class ItalianFactory : public RestaurantFactory {
public:
    Pizza* createPizza() override {
        return new ItalianPizza();
    }

    Burger* createBurger() override {
        return new ItalianBurger();
    }
};

class AmericanFactory : public RestaurantFactory {
public:
    Pizza* createPizza() override {
        return new AmericanPizza();
    }

    Burger* createBurger() override {
        return new AmericanBurger();
    }
};


class FoodOrdering {
private:
    Pizza* pizza;
    Burger* burger;

public:
    FoodOrdering(RestaurantFactory* factory) {
        pizza = factory->createPizza();
        burger = factory->createBurger();
    }

    void orderFood() {
        pizza->prepare();
        burger->prepare();
    }

    ~FoodOrdering() {
        delete pizza;
        delete burger;
    }
};


int main() {
    RestaurantFactory* factory = new ItalianFactory();

    FoodOrdering app(factory);
    app.orderFood();

    delete factory;
    return 0;
}
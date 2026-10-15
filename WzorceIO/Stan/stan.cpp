#include <iostream>
#include <memory>

class VendingMachine;
class HasCoinState;
class NoCoinState;

class State {
public:
    virtual ~State() = default;
    virtual void insertCoin(VendingMachine& machine) = 0;
    virtual void pressButton(VendingMachine& machine) = 0;
};

class VendingMachine {
    std::unique_ptr<State> state;

public:
    VendingMachine(std::unique_ptr<State> initialState) : state(std::move(initialState)) {}

    void setState(std::unique_ptr<State> newState) {
        state = std::move(newState);
    }

    void insertCoin() {
        state->insertCoin(*this);
    }

    void pressButton() {
        state->pressButton(*this);
    }
};

class NoCoinState : public State {
public:
    void insertCoin(VendingMachine& machine) override;
    void pressButton(VendingMachine& machine) override;
};

class HasCoinState : public State {
public:
    void insertCoin(VendingMachine& machine) override;
    void pressButton(VendingMachine& machine) override;
};

void NoCoinState::insertCoin(VendingMachine& machine) {
    std::cout << "Moneta wrzucona.\n";
    machine.setState(std::make_unique<HasCoinState>());
}

void NoCoinState::pressButton(VendingMachine&) {
    std::cout << "Najpierw wrzuć monetę.\n";
}

void HasCoinState::insertCoin(VendingMachine&) {
    std::cout << "Już wrzuciłeś monetę.\n";
}

void HasCoinState::pressButton(VendingMachine& machine) {
    std::cout << "Wydawanie napoju...\n";
    machine.setState(std::make_unique<NoCoinState>());
}

int main() {
    VendingMachine machine(std::make_unique<NoCoinState>());

    machine.pressButton();   // "Najpierw wrzuć monetę."
    machine.insertCoin();    // "Moneta wrzucona."
    machine.insertCoin();    // "Już wrzuciłeś monetę."
    machine.pressButton();   // "Wydawanie napoju..."
    machine.pressButton();   // "Najpierw wrzuć monetę."

    return 0;
}
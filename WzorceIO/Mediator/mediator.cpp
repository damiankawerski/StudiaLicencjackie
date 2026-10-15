#include <iostream>

class Mediator {
public:
    virtual void notify(void* sender, const std::string& event) = 0;
};

class Component {
protected:
    Mediator* mediator;
public:
    Component(Mediator* m) : mediator(m) {}
    void setMediator(Mediator* m) { mediator = m; }
};


class Button : public Component {
public:
    Button(Mediator* m) : Component(m) {}
    void click() {
        std::cout << "Button clicked\n";
        mediator->notify(this, "ButtonClick");
    }
};

class TextBox : public Component {
public:
    TextBox(Mediator* m) : Component(m) {}
    void clear() {
        std::cout << "TextBox cleared\n";
    }
};

class CheckBox : public Component {
private:
    bool checked = false;
public:
    CheckBox(Mediator* m) : Component(m) {}
    void toggle() {
        checked = !checked;
        std::cout << "Checkbox toggled to " << (checked ? "checked" : "unchecked") << "\n";
        mediator->notify(this, "CheckBoxToggle");
    }
};

class ComponentMediator : public Mediator {
private:
    Button* button;
    TextBox* textBox;
    CheckBox* checkBox;
public:
    ComponentMediator(Button* b, TextBox* t, CheckBox* c)
        : button(b), textBox(t), checkBox(c) {}

    void notify(void* sender, const std::string& event) override {
        if (event == "ButtonClick") {
            textBox->clear();
        } else if (event == "CheckBoxToggle") {
            std::cout << "Mediator reacts to CheckBox toggle\n";
        }
    }
};

int main() {
    Button* btn = new Button(nullptr);
    TextBox* txt = new TextBox(nullptr);
    CheckBox* cb = new CheckBox(nullptr);

    ComponentMediator* mediator = new ComponentMediator(btn, txt, cb);

    btn->setMediator(mediator);
    txt->setMediator(mediator);
    cb->setMediator(mediator);

    cb->toggle();
    btn->click();

    delete btn;
    delete txt;
    delete cb;
    delete mediator;

    return 0;
}

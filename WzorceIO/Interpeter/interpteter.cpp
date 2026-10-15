#include <iostream>
#include <memory>
#include <string>

class Expression {
public:
    virtual int interpret() const = 0;
    virtual ~Expression() = default;
};

class NumberExpression : public Expression {
    int number;
public:
    explicit NumberExpression(int number) : number(number) {}
    int interpret() const override {
        return number;
    }
};


class AddExpression : public Expression {
    std::unique_ptr<Expression> left, right;
public:
    AddExpression(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) : left(std::move(l)), right(std::move(r)) {}
    int interpret() const override {
        return left->interpret() + right->interpret();
    }
};

class SubtractExpression : public Expression {
    std::unique_ptr<Expression> left, right;
public:
    SubtractExpression(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) : left(std::move(l)), right(std::move(r)) {}
    int interpret() const override {
        return left->interpret() - right->interpret();
    }
};

int main() {
    // (5 + 3) - 2
    auto expr = std::make_unique<SubtractExpression>(
        std::make_unique<AddExpression>(
            std::make_unique<NumberExpression>(5),
            std::make_unique<NumberExpression>(3)
        ),
        std::make_unique<NumberExpression>(2)
    );

    std::cout << "Wynik: " << expr->interpret() << std::endl; // 6

    return 0;
}

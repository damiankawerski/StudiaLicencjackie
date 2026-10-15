#include <iostream>
#include <vector>
#include <memory>


class Circle;
class Rectangle;

class Visitor {
public:
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Rectangle& rectangle) = 0;
    virtual ~Visitor() = default;
};

class Shape {
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Shape() = default;
};


class Circle : public Shape {
public:
    double radius = 5.0;
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};

class Rectangle : public Shape {
public:
    double width = 3.0, height = 4.0;
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};


class AreaCalculator : public Visitor {
public:
    void visit(Circle& circle) override {
        double area = 3.14159 * circle.radius * circle.radius;
        std::cout << "Area of circle: " << area << std::endl;
    }

    void visit(Rectangle& rectangle) override {
        double area = rectangle.width * rectangle.height;
        std::cout << "Area of rectangle: " << area << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_unique<Circle>());
    shapes.emplace_back(std::make_unique<Rectangle>());

    AreaCalculator calculator;
    for (auto& shape : shapes) {
        shape->accept(calculator);
    }

    return 0;
}

#include <iostream>
#include <memory>

class DrawingAPI {
public:
    virtual void drawCircle(double x, double y, double radius) = 0;
    virtual ~DrawingAPI() = default;
};

class DrawingAPI1 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        std::cout << "API1: Rysuję koło na (" << x << ", " << y << ") z promieniem " << radius << "\n";
    }
};

class DrawingAPI2 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        std::cout << "API2: Rysuję okrąg na (" << x << ", " << y << ") z promieniem " << radius << "\n";
    }
};

class Shape {
public:
    virtual void draw() = 0;
    virtual void resizeByPercentage(double pct) = 0;
    virtual ~Shape() = default;
};


class CircleShape : public Shape {
private:
    double x, y, radius;
    std::shared_ptr<DrawingAPI> drawingAPI;

public:
    CircleShape(double x, double y, double radius, std::shared_ptr<DrawingAPI> api)
        : x(x), y(y), radius(radius), drawingAPI(api) {}

    void draw() override {
        drawingAPI->drawCircle(x, y, radius);
    }

    void resizeByPercentage(double pct) override {
        radius *= pct;
    }
};

int main() {
    std::shared_ptr<Shape> circle1 = std::make_shared<CircleShape>(1, 2, 3, std::make_shared<DrawingAPI1>());
    std::shared_ptr<Shape> circle2 = std::make_shared<CircleShape>(5, 7, 11, std::make_shared<DrawingAPI2>());

    circle1->draw();
    circle2->resizeByPercentage(0.5);
    circle2->draw();

    return 0;
}

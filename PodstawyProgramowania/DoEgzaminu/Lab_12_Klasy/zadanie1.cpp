#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x , y;

public:
    int getX() {return x;}
    int getY() {return y;}

    void setX(int i) {x = i;}
    void setY(int i) {y = i;}
    
};

float distance_points(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + (pow(y2 - y1, 2)));
}

int main() {
    int x, y;
    cin >> x >> y;
    Point punkt1;
    Point punkt2;
    punkt1.setX(x);
    punkt1.setY(y);
    cin >> x >> y;
    punkt2.setX(x);
    punkt2.setY(y);

    cout << distance_points(punkt1.getX(), punkt1.getY(), punkt2.getX(), punkt2.getY());
    return 0;
}

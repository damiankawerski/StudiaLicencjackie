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
    Point point1 = Point();
    point1.setX(2);

    Point *point2 = new Point();
    point2->setX(5);
    delete point2;

    Point array1[3];

    Point* array2[3];
    for(int i = 0 ; i < 3 ; i ++) {
        array2[i] = new Point;
    }
    for(int i = 0 ; i < 3 ; i++) {
        delete array2[i];
    }

    Point *array3 = new Point[3];
    array3[0].setX(5);
    delete[] array3;


    Point **array4 = new Point*[3];
    for(int i = 0 ; i < 3 ; i++) {
        array4[i] = new Point();
    }
    array4[0]->setX(5);
    for(int i = 0 ; i < 3 ; i++) {
        delete array4[i];
    }
    delete[] array4;
    
    return 0;
}

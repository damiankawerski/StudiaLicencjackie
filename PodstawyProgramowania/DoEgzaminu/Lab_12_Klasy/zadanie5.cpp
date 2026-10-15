#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class Point {
private:
    int x , y;

public:
    int getX() {return x;}
    int getY() {return y;}

    void setX(int i) {x = i;}
    void setY(int i) {y = i;}

    float getDistance(Point a) {
        return sqrt(pow(x - a.getX(), 2) + pow(y - a.getY(), 2));
    } 
};

void randomize_points(Point *array, int n) {
    srand(time(0));
    for(int i = 0 ; i < n ; i++) {
        array[i].setX(rand() % 100);
        array[i].setY(rand() % 100);
    }
}

int calculate_size(Point *arr, int n, float a, float b, float r) {
    int size = 0 ;
    Point point0;
    point0.setX(a);
    point0.setY(b);
    for(int i = 0 ; i < n ; i++) {
        if(point0.getDistance(arr[i]) <= r) {
            size++;
        }
    }
    return size;
}

Point **pointsInCircle(Point *arr, int n, float a, float b, float r) {
    int size = calculate_size(arr, n, a, b, r);
    Point point0;
    point0.setX(a);
    point0.setY(b);
    int index = 0;
    Point **result = new Point*[size];
    for(int i = 0 ; i < size ; i++) {
        result[i] = new Point();
    }
    for(int i = 0 ; i < n ; i++) {
        if(point0.getDistance(arr[i]) <= r) {
            //result[index]->setX(arr[i].getX());
            //result[index]->setY(arr[i].getY());
            result[index] = &arr[i];
            index++;
        }
    }
    return result;
}

void show_points(Point** arr, int n) {
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i]->getX() << " : " << arr[i]->getY() << endl;
    }
}


int main() {
    int n = 100;
    Point array[n];
    float a = 0;
    float b = 0;
    float r = 100;
    randomize_points(array, n);
    Point** result = pointsInCircle(array, n, a, b, r);
    show_points(result, calculate_size(array, n, a, b, r));
    return 0;
}
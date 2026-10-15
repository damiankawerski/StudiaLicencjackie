#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
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

void copy_array(Point *arr1, Point *arr2, int size) {
    for(int i = 0 ; i < size ; i++) {
        arr2[i] = arr1[i];
    }
}

void show_points(Point *arr, int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i].getX() << " : " << arr[i].getY() << endl;
    }
}

void fill_points(Point *arr, int size) {
    srand(time(0));
    int x, y;
    for(int i = 0 ; i < size ; i++) {
        x = rand() % 10;
        y = rand() % 10;
        arr[i].setX(x);
        arr[i].setY(y);
    }
}

int main() {
    int N = 3;
    Point *points1 = new Point[N];
    Point *points2 = new Point[N];


    fill_points(points1, N);
    show_points(points1, N);
    cout << "***********************" << endl;
    copy_array(points1, points2, N);
    show_points(points2, N);

    delete[] points1;
    delete[] points2;
    return 0;
}


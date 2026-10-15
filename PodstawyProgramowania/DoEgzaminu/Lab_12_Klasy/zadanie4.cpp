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

float lowest_distance(Point *arr, int size) {
    float result_min = arr[0].getDistance(arr[1]); 
    for(int i = 0 ; i < size - 1 ; i++) {
        for(int j = i + 1 ; j < size ; j++) {
                float distance = arr[i].getDistance(arr[j]);
                if(result_min > distance) {
                    result_min = distance;
                }
        }
    }
    return result_min;
}

void fill_points(Point *arr, int size) {
    
    int x, y;
    for(int i = 0 ; i < size ; i++) {
        arr[i].setX(i);
        arr[i].setY(i);
    }
}

int main() {
    int size = 4;
    Point points[size];
    fill_points(points, size);
    float result = lowest_distance(points, size);
    cout << result << endl;
    return 0;
}


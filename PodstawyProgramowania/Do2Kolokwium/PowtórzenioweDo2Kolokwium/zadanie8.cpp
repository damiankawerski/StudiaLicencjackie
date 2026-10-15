#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct PolarCoordinate {
    double R;
    double F;
};

void sortPolarCoordinates(PolarCoordinate coordinates[], int n) {
    for(int i = 0 ; i < n ; i++) {
        for(int j = i + 1 ; j < n ; j++) {
            if(coordinates[i].R > coordinates[j].R || (coordinates[i].R == coordinates[j].R && 
            coordinates[i].F < coordinates[j].F)) {

                swap(coordinates[i], coordinates[j]);
            }
        }
    }
}

void convertAndShow(PolarCoordinate coords[], int n) {
    for(int i = 0 ; i < n ; i++) {
        double x = coords[i].R * cos(coords[i].F);
        double y = coords[i].R * sin(coords[i].F);
        printf("%.3f  %.3f\n", x, y);
    }
}

int main() {
    const int n = 3;  // Zmień na odpowiednią liczbę obiektów
    PolarCoordinate coordinates[n] = {{1.2, 6.1}, {1.2, 1.1}, {5.4, 3.1}};
    sortPolarCoordinates(coordinates, n);
    convertAndShow(coordinates, n);
    return 0;
}
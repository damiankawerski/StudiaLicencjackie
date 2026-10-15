#include <iostream>
using namespace std;



struct Rect {
    float a;
    float b;
};

void print_rect(Rect rect) {
    cout << rect.a << " " << rect.b << endl;
}

float area(Rect rect) {
    return rect.a * rect.b;
}

int main() {
    Rect rect1 = {10, 5};
    print_rect(rect1);
    cout << area(rect1) << endl;
    return 0;
}
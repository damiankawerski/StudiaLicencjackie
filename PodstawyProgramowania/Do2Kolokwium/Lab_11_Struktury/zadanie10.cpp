#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

struct vec2d {
    float x;
    float y;
};

void generate_condition(vec2d &vector1) {
    vector1.x = static_cast<float>(rand()) / RAND_MAX * 2 - 1;
    vector1.y = -vector1.x;
}

void show_vec2d(const vec2d &vector1) {
    cout << "[" << vector1.x << ":" << vector1.y << "]" << "  "; 
}

bool sort_condition(const vec2d &vector1, const vec2d &vector2) {
    return vector1.y < vector2.y;
}

bool min_condition(const vec2d &a, const vec2d &b) {
    return a.x < b.x;
}

int main() {
    const int size = 10;
    vec2d vector_array[size];
    
    for_each(vector_array, vector_array + size, generate_condition);
    
    cout << "Wektory przed sortowaniem:" << endl;
    for_each(vector_array, vector_array + size, show_vec2d);
    cout << endl;
    
    sort(vector_array, vector_array + size, sort_condition);
    
    cout << "Wektory po sortowaniu malejąco względem współrzędnej y:" << endl;
    for_each(vector_array, vector_array + size, show_vec2d);
    cout << endl;
    
    vec2d* result = min_element(vector_array, vector_array + size, min_condition);
    
    cout << "Wektor o najmniejszej współrzędnej x:" << endl;
    show_vec2d(*result);
    cout << endl;
    
    return 0;
}
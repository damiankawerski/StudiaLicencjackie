#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int x;

int genereteCondition() {
    return x++;
}

void show(float a) {
    cout << a << " ";
}

int main() {
    int n;
    cin >> n >> x;
    int temp = x;
    float vector1[n];
    float vector2[n];
    generate(vector1, vector1 + n, genereteCondition);
    x = temp;
    generate(vector2, vector2 + n, genereteCondition);
    random_shuffle(vector1, vector1 + n);
    random_shuffle(vector2, vector2 + n);
    for_each(vector1, vector1 + n, show);
    cout << endl;
    for_each(vector2, vector2 + n, show);
    cout << endl << "Suma 1: " << accumulate(vector1, vector1 + n, 0);
    cout << endl << "Suma 2: " <<  accumulate(vector2, vector2 + n, 0);
    cout << endl << "Iloczyn: " << inner_product(vector1, vector1 + n, vector2, 0);
    return 0;
}
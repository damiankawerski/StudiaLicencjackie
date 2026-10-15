#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int d;

bool compare(int x) {
    return (x - '0') == 4;
}

int main() {
    int x;
    cin >> x >> d;
    char str[12];
    snprintf(str, 12, "%d" , x);
    int counter = count_if(str, str + strlen(str), compare);
    cout << counter << endl;
    return 0;
}
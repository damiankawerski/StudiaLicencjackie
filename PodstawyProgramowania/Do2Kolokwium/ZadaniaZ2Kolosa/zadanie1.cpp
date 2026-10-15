#include <iostream>
using namespace std;

bool help_fun(int id, int v1, int v2) {
    return ((v1 * v2) % 2) == 0;
}

int filter_measures(int *start, int *end, int *result, bool (*fn)(int, int, int)) {
    int counter = 0;
    while(start < end) {
        if(fn(*start, *(start + 1), *(start + 2))) {
            if(result == nullptr) {
                counter++;
            }
            else {
                *result = *start;
                result++;
                counter++;
            }
        }
        start += 3;
    }
    return counter;
}

int main() {
    int n = 4;
    int N = 3 * n;
    int *input = new int[N] {0, 1, 5, 6, 3, 8, 2, 11, 44, 19, 1, 33};
    int result_size = filter_measures(input, input + N, nullptr, help_fun);
    int *result = new int[result_size];
    filter_measures(input, input + N, result, help_fun);
    for(int i = 0 ; i < result_size ; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] input;
    delete[] result;
    return 0;
}
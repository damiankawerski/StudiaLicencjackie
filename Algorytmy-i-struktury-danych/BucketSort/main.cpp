#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>

using namespace std;

struct bucket {
    double min;
    double max;
    bool is_empty;

    bucket() : min(INT_MAX), max(INT_MIN), is_empty(true) {}

    void push(double value) {
        if (is_empty) {
            min = max = value;
            is_empty = false;
        } else {
            if (value < min) min = value;
            if (value > max) max = value;
        }
    }
};

double bucket_sort(double *arr, int size) {

    double min = arr[0];
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int bucket_count = size;
    bucket* buckets = new bucket[bucket_count];

    double range = (max - min) / (bucket_count - 1);

    for (int i = 0; i < size; i++) {
        int index = static_cast<int>((arr[i] - min) / range);

        if (index >= bucket_count) index = bucket_count - 1;

        buckets[index].push(arr[i]);
    }

    double max_gap = 0.0;
    double prev_max = min;

    for (int i = 0; i < bucket_count; i++) {
        if (!buckets[i].is_empty) {
            double current_gap = buckets[i].min - prev_max;
            if (current_gap > max_gap) {
                max_gap = current_gap;
            }
            prev_max = buckets[i].max;
        }
    }

    delete[] buckets;

    return max_gap;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int size;
    cin >> size;

    double* arr = new double[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    double answer = bucket_sort(arr, size);
    cout << fixed << setprecision(4) << answer << '\n';

    delete[] arr;

    return 0;
}
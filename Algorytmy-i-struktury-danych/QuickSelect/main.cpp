#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int MAX_VAL = 1000000;

void calculate_prime_factors(vector<int>& prime_factors_count) {
    for (int i = 2; i <= MAX_VAL; ++i) {
        if (prime_factors_count[i] == 0) {
            for (int j = i; j <= MAX_VAL; j += i) {
                prime_factors_count[j]++;
            }
        }
    }
}


// Wybierz k-ty element
int quick_select(vector<int> arr, int k) {
    if (arr.size() == 1) {
        return arr[0];
    }

    int pivot = arr[arr.size() / 2];
    vector<int> left, middle, right;

    for (int num : arr) {
        if (num < pivot) {
            left.push_back(num);
        } else if (num > pivot) {
            right.push_back(num);
        } else {
            middle.push_back(num);
        }
    }

    int left_size = left.size();

    if (k < left_size) {
        return quick_select(left, k);
    } else if (k < left_size + middle.size()) {
        return pivot;
    } else {
        return quick_select(right, k - left_size - middle.size());
    }
}

void print_vector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t;
    cin >> t;

    vector<int> prime_factors_count(MAX_VAL, 0);
    calculate_prime_factors(prime_factors_count);

    while (t--) {
        int n;
        cin >> n;
        int max_number = 0;

        vector<int> stable_numbers;

        for (int i = 0;  i < n ; i++) {
            int temp;
            cin >> temp;
            if(prime_factors_count[temp] % 2 == 0) {
                stable_numbers.push_back(temp);
            }
        }

        int k;
        cin >> k;

        if (k >= stable_numbers.size()) {
            cout << "BRAK DANYCH\n";
            continue;
        }

        cout << quick_select(stable_numbers, k) << '\n';
    }
}
#include <iostream>
#include <climits>
using namespace std;

class matrix_backtracker {
private:
    int** matrix;
    int N;
    int min_sum;
    int* best_rows;

    void dfs(int col, int sum, bool* used_rows, bool* used_cols, int* current_rows, int depth) {
        if (sum >= min_sum) {
            return;
        }

        if (col == N) {
            min_sum = sum;

            for (int i = 0; i < N; i++) {
                best_rows[i] = current_rows[i];
            }
            return;
        }

        for (int row = 0; row < N; row++) {
            if (!used_rows[row] && !used_cols[col]) {
                used_rows[row] = true;
                used_cols[col] = true;

                current_rows[depth] = row;

                dfs(col + 1, sum + matrix[row][col], used_rows, used_cols, current_rows, depth + 1);

                used_rows[row] = false;
                used_cols[col] = false;
            }
        }
    }

public:
    matrix_backtracker(int** input, int size) : matrix(input), N(size), min_sum(INT_MAX) {
        best_rows = new int[size];
    }

    ~matrix_backtracker() {
        delete[] best_rows;
    }

    void find_path() {
        bool* used_rows = new bool[N]();
        bool* used_cols = new bool[N]();
        int* current_rows = new int[N];

        dfs(0, 0, used_rows, used_cols, current_rows, 0);

        for (int i = 0; i < N; i++) {
            cout << best_rows[i] << " ";
        }
        cout << '\n';

        delete[] used_rows;
        delete[] used_cols;
        delete[] current_rows;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int** matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    matrix_backtracker path_finder(matrix, N);
    path_finder.find_path();

    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
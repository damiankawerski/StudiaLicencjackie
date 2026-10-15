#include <iostream>
#include <vector>
using namespace std;

void fill_dynamic_table_from_top(vector<vector<int>> &arr, vector<vector<int>> &dp, int N) {
    dp[0][0] = arr[0][0];
    for (int i = 1; i < N; ++i) {
        dp[i][0] = dp[i-1][0] + arr[i][0];
        dp[0][i] = dp[0][i-1] + arr[0][i];
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
        }
    }
}

void take_down_ones(vector<vector<int>> &arr, vector<vector<int>> &dp, int N) {
    int i = N - 1;
    int j = N - 1;

    while(i > 0 || j > 0) {
        arr[i][j] = 0;

        if(i > 0 && j > 0) {
            if(dp[i-1][j] < dp[i][j-1]) {
                j--;
            } else {
                i--;
            }
        } else if(i > 0) {
            i--;
        } else {
            j--;
        }
    }
    arr[0][0] = 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int N;
    cin >> N;

    vector<vector<int>> macierz(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int temp;
            cin >> temp;
            macierz[i][j] = temp;
        }
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));
    fill_dynamic_table_from_top(macierz, dp, N);
    take_down_ones(macierz, dp, N);
    int result = dp[N - 1][N - 1];
    fill_dynamic_table_from_top(macierz, dp, N);
    result += dp[N - 1][N - 1];
    cout << result << endl;

    return 0;
}
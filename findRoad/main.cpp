#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &nums[i][j]);
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i][0] == nums[i - 1][0]) {
            dp[i][0] = dp[i - 1][0] + 1;
        } else {
            dp[i][0] = dp[i - 1][0] + 2;
        }
    }
    for (int i = 1; i < m; i++) {
        if (nums[0][i] == nums[0][i - 1]) {
            dp[0][i] = dp[0][i - 1] + 1;
        } else {
            dp[0][i] = dp[0][i - 1] + 2;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + (nums[i - 1][j] == nums[i][j] ? 1 : 2));
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + (nums[i][j - 1] == nums[i][j] ? 1 : 2));
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}

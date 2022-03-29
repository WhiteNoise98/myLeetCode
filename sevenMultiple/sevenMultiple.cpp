#include "bits/stdc++.h"
using namespace std;

int mod(int a, int b) {
    int c = floor(double(a) / double(b));
    return a - b * c;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nums[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(7, INT_MIN));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 7; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][mod(j - nums[i], 7)] + nums[i]);
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}


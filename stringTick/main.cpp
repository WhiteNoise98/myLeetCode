#include "bits/stdc++.h"
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        if (s[i] == s[i - 1]) {
            dp[i] = max(dp[i], dp[i - 1] + ((s[i] - 'a' + 1) * 2));
        } else if (abs(s[i] - s[i - 1]) == 1) {
            dp[i] = max(dp[i], dp[i - 1] + (s[i] - 'a' + 1) + (s[i - 1] - 'a' + 1));
        }
    }
    cout << dp[n - 1] << endl;

    return 0;
}

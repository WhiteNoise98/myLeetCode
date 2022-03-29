#include "bits/stdc++.h"
using namespace std;

int a, b, x, y;
int dfs(int a, int b) {
    if (a <= 0 && b <= 0) {
        return 0;
    }
    int ans = INT_MAX;
    if (a > 0) {
        ans = min(ans, dfs(max(a - x, 0), b) + 1);
    }
    if (b > 0) {
        ans = min(ans, dfs(a, max(b - x, 0)) + 1);
    }
    ans = min(ans, dfs(max(0, a - y), max(0, b - y)) + 1);
    return ans;
}
int main() {
    cin >> a >> b >> x >> y;
    int res;
    res = dfs(a, b);
    cout << res << endl;
    return 0;
}
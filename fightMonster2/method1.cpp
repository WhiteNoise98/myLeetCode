#include "bits/stdc++.h"
using namespace std;

int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int res = 0;
    if (y >= a && y >= b) {
        res = 1;
    } else {
        while (a > 0 && b > 0) {
            if (x > 2 * y) {
                a -= x;
                b -= x;
                res += 2;
            } else {
                a -= y;
                b -= y;
                res++;
            }
        }
        int c = a >= b ? a : b;
        if (c > 0) {
            res += c / max(x, y);
            if (c % max(x, y) > 0) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const double e = 10e-4;

int main() {
    freopen ("folding.in", "r", stdin);
    freopen ("folding.out", "w", stdout);
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < c || b < d) {
        swap (c, d);
        if (a < c || b < d) {
            cout << -1;
            return 0;
        }
    }
    int ans = 0;
    while (a / 2 > c) {
        a /= 2;
        ans++;
    }
    if (fabs(a - c) > e) {
        ans++;
    }
    while (b / 2 > d) {
        b /= 2;
        ans++;
    }
    if (fabs(b - d) > e) {
        ans++;
    }
    cout << ans;
    return 0;
}

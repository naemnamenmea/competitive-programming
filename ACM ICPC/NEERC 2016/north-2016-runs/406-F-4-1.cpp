#include <bits/stdc++.h>
using namespace std;

const double e = 1e-4;

int main() {
    freopen ("folding.in", "r", stdin);
    freopen ("folding.out", "w", stdout);
    double a, b, c, d, ta, tb;
    cin >> a >> b >> c >> d;
    ta = b;
    tb = a;
    bool f = 1;
    if (a < c || b < d) {
        swap (c, d);
        f = 0;
        if (a < c || b < d) {
            cout << -1;
            return 0;
        }
    }
    int ans = 0;
    while (a / 2. > c) {
        a /= 2.;
        ans++;
    }
    if (fabs(a - c) > e) {
        ans++;
    }
    while (b / 2. > d) {
        b /= 2.;
        ans++;
    }
    if (fabs(b - d) > e) {
        ans++;
    }
    int tans = ans;
    if (f) {
        tans = 0;
        while (ta / 2. > c) {
            ta /= 2.;
            tans++;
        }
        if (fabs(ta - c) > e) {
            tans++;
        }
        while (tb / 2. > d) {
            tb /= 2.;
            tans++;
        }
        if (fabs(tb - d) > e) {
            tans++;
        }
    }
    cout << min(ans, tans);
    return 0;
}

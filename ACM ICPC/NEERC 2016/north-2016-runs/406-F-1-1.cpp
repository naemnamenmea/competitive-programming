#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("folding.in", "r", stdin);
    freopen ("folding.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c > a && c > b || d > a && d > b) {
        cout << -1;
        return 0;
    }
    if (a < c || b < d) {
        swap(c, d);
    }
    int ans = 0;
    while (a / 2 > c) {
        a /= 2;
        ans++;
    }
    if (a != c) {
        ans++;
    }
    while (b / 2 > d) {
        b /= 2;
        ans++;
    }
    if (b != d) {
        ans++;
    }
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int ans = 1000000000;

void solve(int H, int W, int h, int w, int cur) {
    if (H < h)
        return;
    if (W < w)
        return;
    int d = 0, q = 0;
    while (H > 2 * h) {
        q |= H & 1;
        H /= 2;
        cur++;
    }
    while (W > 2 * w) {
        d |= W & 1;
        W /= 2;
        cur++;
    }
    if (H != h)
        cur++;
    if (W != w)
        cur++;
    if (H != 2 * h) {
        q = 0;
    }
    if (W != 2 * w) {
        d = 0;
    }
//    cout << "Here\n";
    ans = min(ans, cur + q + d);
}

int main() {
    freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);
    int H, W;
    int h, w;
    cin >> H >> W >> h >> w;
    solve(H, W, h, w, 0);
    solve(H, W, w, h, 0);
    if (ans == 1000000000) {
        cout << -1;
    } else {
        cout << ans;
    }
}

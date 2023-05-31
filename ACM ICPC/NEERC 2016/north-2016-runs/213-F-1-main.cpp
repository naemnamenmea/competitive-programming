#include <bits/stdc++.h>

using namespace std;

#define FILE "folding"

int W, H, w, h;

int solve(int W, int H, int w, int h) {
    if (W < w || H < h) {
        return -1;
    }

    int ans = 0;
    while (2 * w <= W) {
        ++ans;
        w *= 2;
    }

    if (W != w) {
        ++ans;
    }

    while (2 * h <= H) {
        ++ans;
        h *= 2;
    }

    if (H != h) {
        ++ans;
    }

    return ans;
}

int main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    cin >> W >> H >> w >> h;
    int a1 = solve(W, H, w, h);
    int a2 = solve(W, H, h, w);

    if (a1 == -1  && a2 == -1) {
        cout << -1 << endl;
        return 0;
    }

    if (a1 == -1 || a2 == -1) {
        cout << (a1 == -1 ? a2 : a1) << endl;
        return 0;
    }

    cout << min(a1, a2) << endl;

    return 0;
}

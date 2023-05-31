#include <bits/stdc++.h>

using namespace std;

int ans = 1000000000;

void solve(int H, int W, int h, int w, int cur) {
    if (H < h)
        return;
    if (W < w)
        return;
    while (h < H) {
        h *= 2;
        cur++;
    }
    while (w < W) {
        w *= 2;
        cur++;
    }
//    cout << "Here\n";
    ans = min(ans, cur);
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

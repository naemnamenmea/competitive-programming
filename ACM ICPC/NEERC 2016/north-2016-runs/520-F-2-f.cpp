#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 1000;

int main() {
    freopen("folding.in","r",stdin);
    freopen("folding.out","w",stdout);
    int W, H, w, h, w0, h0;
    cin >> W >> H >> w >> h;
    if (W < H) swap(W, H);
    if (w < h) swap(w, h);
    w0 = W, h0 = H;
    if (w > W || h > H) {cout << -1; return 0;}
    int ans = 0;
    while (w < W) W = (W / 2) + (W % 2 != 0), ++ans;
    while (h < H) H = (H / 2) + (H % 2 != 0), ++ans;
    int ans2 = 0;
    W = w0, H = h0;
    swap(W, H);
    if (w > W || h > H) ans2 = inf;
    else {
        while (w < W) W = (W / 2) + (W % 2 != 0), ++ans2;
        while (h < H) H = (H / 2) + (H % 2 != 0), ++ans2;
    }
    cout << min(ans, ans2);
    return 0;
}

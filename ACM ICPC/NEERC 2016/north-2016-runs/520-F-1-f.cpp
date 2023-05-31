#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("folding.in","r",stdin);
    freopen("folding.out","w",stdout);
    int W, H, w, h;
    cin >> W >> H >> w >> h;
    if (W < H) swap(W, H);
    if (w < h) swap(w, h);
    if (w > W || h > H) {cout << -1; return 0;}
    int ans = 0;
    while (w < W) W = (W / 2) + (W % 2 != 0), ++ans;
    while (h < H) H = (H / 2) + (H % 2 != 0), ++ans;
    cout << ans;
    return 0;
}

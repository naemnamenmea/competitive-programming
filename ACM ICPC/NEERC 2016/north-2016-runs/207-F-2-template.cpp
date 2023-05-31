#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);
    
    int W, H, w, h;

    cin >> W >> H >> w >> h;

    if (W < H)
        swap(W, H);

    if (w < h)
        swap(w, h);

    if (w > W || h > H) {
        cout << -1;
        return 0;
    }

    int cur_w = W, cur_h = H;
    int res = 0;
    while (W > w) {
        W = (W + 1) / 2;
        res++;
    }
    while (H > h) {
        H = (H + 1) / 2;
        res++;
    }

    W = cur_w;
    H = cur_h;
    int res2 = 0;
    while (W > h) {
        W = (W + 1) / 2;
        res2++;
    }
    while (H > w) {
        H = (H + 1) / 2;
        res2++;
    }

    cout << min(res, res2);
    

    return 0;
}
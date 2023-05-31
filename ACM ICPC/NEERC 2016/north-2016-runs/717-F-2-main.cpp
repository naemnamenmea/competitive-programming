#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define push_back pb

void solve() {
    int W, H, w, h;

    cin >> W >> H >> w >> h;

    if (W < H)
        swap(W, H);

    if (w < h)
        swap(w, h);

    if (w > W || h > H) {
        cout << -1;
        return;
    }

    int ans = 0;

    while (W > w && H > h) {
        W = (W + 1) / 2;
        ans++;
        if (H > W)
            swap(H, W);
    }

    while (W > w)
        ans++, W = (W + 1) / 2;

    while (H > h)
        ans++, H = (H + 1) / 2;

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "folding"
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    solve();
    return 0;
}
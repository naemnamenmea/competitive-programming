#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define mkp make_pair
const int maxn = (int)2e5 + 1000;
int x[maxn], y[maxn];
int cnt[2][2][2];
int P[maxn];

int f(int x1, int x2, int y1, int y2) {
    return (((x2 - x1) % 2 != 0) && ((y2 - y1) % 2 != 0));
}

int main() {
    freopen("integral.in","r",stdin);
    freopen("integral.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        if (i < n) cin >> x[i] >> y[i];
        else x[i] = x[0], y[i] = y[0];
        if (i) {
            P[i] = (P[i - 1] + f(x[i], x[i - 1], y[i], y[i - 1])) % 2;
        }
        if (i == n) break;
        ++cnt[P[i]][abs(x[i]) % 2][abs(y[i]) % 2];
    }
    if (P[n]) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int p = 0; p < 2; ++p) {
            for (int x2 = 0; x2 < 2; ++x2) {
                for (int y2 = 0; y2 < 2; ++y2) {
                    int cur = p + f(x[i], x2, y[i], y2) - P[i];
                    if (cur % 2 == 0) {
                        ans += cnt[p][x2][y2];
                    }
                }
            }
        }
        ans -= 3;
    }
    cout << ans / 2;
    return 0;
}

/*
5
7 3
3 5
1 4
2 1
5 0

4
1 1
3 1
5 5
1 3

4
0 0
0 1
1 0
1 1
*/

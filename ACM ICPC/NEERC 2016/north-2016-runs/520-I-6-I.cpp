#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<ll, ll>
#define F first
#define S second
#define mkp make_pair
#define ll long long
const ll maxn = (ll)2e5 + 1000;
ll x[maxn], y[maxn];
ll cnt[2][2][2];
ll P[maxn];

ll f(ll x1, ll x2, ll y1, ll y2) {
    return (x2 - x1) % 2 == 0 && (y2 - y1) % 2 == 0;
}

int main() {
    freopen("integral.in","r",stdin);
    freopen("integral.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i <= n; ++i) {
        if (i < n) cin >> x[i] >> y[i];
        else x[i] = x[0], y[i] = y[0];
        if (i) {
            P[i] = (P[i - 1] + f(x[i], x[i - 1], y[i], y[i - 1]) + 1) % 2;
        } else {
            P[i] = 1;
        }
        if (i == n) {P[i] = !P[i]; break;}
        cerr << i << " :                 " << P[i] << endl;
        ++cnt[P[i] % 2][abs(x[i]) % 2][abs(y[i]) % 2];
    }
    if (P[n]) {
        cout << 0;
        return 0;
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll p = 0; p < 2; ++p) {
            for (ll x2 = 0; x2 < 2; ++x2) {
                for (ll y2 = 0; y2 < 2; ++y2) {
                    ll cur = p - P[i] + 1 + f(x[i], x2, y[i], y2);
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

5
0 0
2 3
4 0
4 -3
0 -3
*/

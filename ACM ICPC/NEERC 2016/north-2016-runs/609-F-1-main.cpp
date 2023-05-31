#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define forab(i,a,b) for( int i = (a); i < (b); i++)
#define forn(i,n) forab(i,0,n)

int f(int n, int m) {
    if (n == m) return 0;
    if ((n + 1) / 2 <= m) return 1;
    return f((n + 1) / 2, m) + 1;
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("folding.in", "r", stdin); freopen("folding.out", "w", stdout);

    int W, H, w, h;
    cin >> W >> H >> w >> h;

    int ans1 = -1;
    if (W >= w && H >= h) ans1 = f(W, w) + f(H, h);
    int ans2 = -1;
    if (W >= h && H >= w) ans2 = f(W, h) + f(H, w);

    if (ans1 == -1) {
        cout << ans2 << endl;
    } else if (ans2 = -1) {
        cout << ans1 << endl;
    } else {
        cout << min(ans1, ans2) << endl;
    }

    return 0;
}

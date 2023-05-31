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

const int maxn = 200200;

int block[2][2][maxn];
int typ[2][2][maxn];

int cnt[2][2][2];
int x[maxn], y[maxn];

long long cross_product(ll a, ll b, ll c, ll d) {
    return a * d - b * c;
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("integral.in", "r", stdin); freopen("integral.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0];
    y[n] = y[0];

    long long s = 0;
    for (int i = 0; i < n; ++i) {
        s += (cross_product(x[i], y[i], x[i + 1], y[i + 1])) % 2;
    }
    if (s % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i1 = 0; i1 <= 1; ++i1) {
        for (int j1 = 0; j1 <= 1; ++j1) {

            for (int i = 0; i < n; ++i) {
                typ[i1][j1][i] = abs(cross_product(x[i] - i1, y[i] - j1, x[i + 1] - i1, y[i + 1] - j1)) % 2;
            }
            int t = 0;
            for (int i = 0; i < n; ++i) {
                if (typ[i1][j1][i]) t = 1 - t;
                block[i1][j1][i] = t;
                cnt[i1][j1][t]++;
            }

        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        if (j == n) j = 0;

        int i1 = abs(x[i]) % 2;
        int j1 = abs(y[i]) % 2;

        int bl;
        if (typ[i1][j1][j] == 0) bl = block[i1][j1][j];
        else bl = 1 - block[i1][j1][j];

        long long cur = cnt[i1][j1][bl];

        if (block[i1][j1][i] == bl) cur--;
        int k = i - 1;
        if (k == -1) k = n - 1;
        if (block[i1][j1][k] == bl) cur--;

        k--;
        if (k == -1) k = n - 1;
        if (block[i1][j1][k] == bl) cur--;

        ans += cur;
    }

    cout << ans / 2 << endl;

    return 0;
}

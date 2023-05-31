#define FNAME "integral"

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (n); i++)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin() v.end()

using namespace std;

typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int M = 4e5 + 30;
int dp[M][2][2][2];
int x[M], y[M];
ll value[M], curv[M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);


    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = n; i <= 2 * n; i++) x[i] = x[i - n], y[i] = y[i - n];

    for (int i = 0; i < n; i++) {
        value[i + 1] = (1LL * x[i] * y[i + 1] - 1LL * x[i + 1] * y[i]);
        value[i + n + 1] = value[i + 1];
    }
    for (int i = 1; i <= 2 * n; i++) {
        curv[i] = (curv[i - 1] + value[i]) % 2;
        for (int v = 0; v < 2; v++) {
            for (int bx = 0; bx < 2; bx++) {
                for (int by = 0; by < 2; by++) {
                    dp[i][v][bx][by] = dp[i - 1][v][bx][by];
                    if (curv[i] % 2LL == 0 && x[i % n] % 2 == bx && y[i % n] % 2 == by) dp[i][v][bx][by]++; 
                }
            }
        }
    }
    if (curv[n] % 2) {
        cout << 0;
        return 0;
    }

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        for (int bx = 0; bx < 2; bx++) {
            for (int by = 0; by < 2; by++) {
                LL v = (1LL * bx * y[i] + 1LL * by * x[i]) % 2;
                v = (v + curv[i]) % 2;
                ans += dp[i + n - 2][v][bx][by] - dp[i + 1][v][bx][by];
            }
        }
    }
    cout << ans / 2<< endl;
    return 0;
}
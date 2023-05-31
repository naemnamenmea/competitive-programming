#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;

#define push_back pb

const int MAXN = 100 * 1000 + 1;

struct Guy {
    int x;
    int y;
    int i;
} guys[MAXN];
int maxpr[MAXN];
int ans[MAXN];

bool comp(Guy a, Guy b) {
    return a.x > b.x;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> guys[i].x >> guys[i].y;
        guys[i].i = i;
    }
    sort(guys, guys + n, comp);

    maxpr[n - 1] = guys[n - 1].y;
    for (int i = n - 2; i >= 0; i--)
        maxpr[i] = max(guys[i].y, maxpr[i + 1]);

    int i = 0;
    int yval;
    while (i < n) {
        yval = guys[i].y;
        int piv = i;
        int last = i;
        while(1) {
            int bl = piv + 1, br = n - 1;
            while (bl <= br) {
              int bm = (bl + br) / 2;
              if (maxpr[bm] > yval) {
                  last = bm;
                  bl = bm + 1;
              } else
                  br = bm - 1;
            }
            for (int j = piv; j <= last; j++)
                yval = min(yval, guys[j].y);
            if (last == piv)
                break;
            piv = last;
        }
        int res = n - 1 - i;
        for (int j = i; j <= last; j++)
            ans[guys[j].i] = res;
        i = last + 1;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "codecoder"
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    solve();
    return 0;
}
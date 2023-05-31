#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define TASK "integral"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;

void precalc() {
}

const int maxn = (int) 2e5 + 100;

int n;

pair<ll, ll> ps[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &ps[i].first, &ps[i].second);
  }
  return 1;
}

int sums[maxn];
int cnt[4][2];
int want[4][4];

void solve() {
  ps[n] = ps[0];
  sums[0] = 0;
  for (int i = 0; i < n; i++) {
    sums[i + 1] = sums[i] ^ (((ll) ps[i].first * ps[i + 1].second - (ll) ps[i].second * ps[i + 1].first) & 1);
  }
  for (int mask1 = 0; mask1 < 4; mask1++) {
    for (int mask2 = 0; mask2 < 4; mask2++) {
      want[mask1][mask2] = (mask1 & 1 & ((mask2 & 2) >> 1)) ^ (((mask1 & 2) >> 1) & mask2 & 1);
    }
  }
  memset(cnt, 0, sizeof(cnt));
  ll res = 0;
  for (int i = 0; i < n; i++) {
    int curmask = (ps[i].first & 1) ^ ((ps[i].second & 1) << 1);
    if (i) {
      for (int mask2 = 0; mask2 < 4; mask2++) {
        int curwant = want[curmask][mask2] ^ sums[i];
        res += cnt[mask2][curwant];
      }
    }
    cnt[curmask][sums[i]]++;
  }
  assert(res >= n);
  printf("%lld\n", res - n);
}

int main() {
  precalc();  
  freopen(TASK ".out", "w", stdout);
  freopen(TASK ".in", "r", stdin);
  
  while (read()) {
    solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}
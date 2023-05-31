#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define TASK "hard"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;

const int maxn = 60 + 5;

int dp[maxn][maxn];
int pr[maxn][maxn][2];

void precalc() {
  for (int w = 0; w < maxn; ++w) {
    for (int h = 0; h < maxn; ++h) {
      int &cur = dp[w][h];
      auto &curp = pr[w][h];
      cur = inf;
      if (!w || !h) {
        cur = 0;
        continue;
      }
      
      if (w == h) {
        cur = 1;
        continue;
      }
      
      for (int x = 1; x < w; ++x) {
        int val = dp[x][h] + dp[w - x][h];
        if (cur > val) {
          cur = val;
          curp[0] = 0, curp[1] = x;
        }
      }
      
      for (int x = 1; x < h; ++x) {
        int val = dp[w][x] + dp[w][h - x];
        if (cur > val) {
          cur = val;
          curp[0] = 1, curp[1] = x;
        }
      }
    }
  }
}

int w, h;
int read() {
  if (scanf("%d%d", &w, &h) < 2) {
    return 0;
  }
  return 1;
}

void gen(int w, int h, int dx, int dy) {
  if (dp[w][h] == 0) {
    return;
  }
  if (dp[w][h] == 1) {
    printf("%d %d %d\n", dx, dy, w);
    return;
  }
  int x = pr[w][h][1];
  if (pr[w][h][0] == 0) {
    gen(x, h, dx, dy);
    gen(w - x, h, dx + x, dy);
  } else {
    gen(w, x, dx, dy);
    gen(w, h - x, dx, dy + x);
  }
}

void solve() {
  printf("%d\n", dp[w][h]);
  gen(w, h, 0, 0);
}

int main() {
  precalc();  
  freopen(TASK ".out", "w", stdout);
  freopen(TASK ".in", "r", stdin);
  
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}
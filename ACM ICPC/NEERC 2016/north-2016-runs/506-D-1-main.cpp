#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define TASK "digital"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;

void precalc() {
}

const int maxn = 105, h = 9, d = 10;
int n;
int a[h][maxn];
int dp[maxn][d][d][2];
int p[maxn][d][d][2][3];
int ans[3][maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n + (i & 1); j++) {
      scanf("%d", &a[i][j]);
    }
    reverse(a[i], a[i] + n + (i & 1));
  }
  return 1;
}

const int hd = 5;
int dig[d][hd][2] = {
{{1, 0}, {1, 1}, {0, 0}, {1, 1}, {1, 0}},
{{0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
{{1, 0}, {1, 0}, {1, 0}, {0, 1}, {1, 0}},
{{1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}},
{{0, 0}, {1, 1}, {1, 0}, {1, 0}, {0, 0}},
{{1, 0}, {0, 1}, {1, 0}, {1, 0}, {1, 0}},
{{1, 0}, {0, 1}, {1, 0}, {1, 1}, {1, 0}},
{{1, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}},
{{1, 0}, {1, 1}, {1, 0}, {1, 1}, {1, 0}},
{{1, 0}, {1, 1}, {1, 0}, {1, 0}, {1, 0}}
};
int b[h];

bool good(int pos, int x, int y, int z, int px, int py, int pz) {
  for (int i = 0; i < h; i++) {
    b[i] = false;
  }
  for (int i = 0; i < hd; i++) {
    b[i] |= dig[x][i][0];
  }
  for (int i = 0; i < hd; i++) {
    b[2 + i] |= dig[y][i][0];
  }
  for (int i = 0; i < hd; i++) {
    b[4 + i] |= dig[z][i][0];
  }
  if (pos) {
    b[1] |= dig[px][1][1];
    b[3] |= (dig[px][3][1] | dig[py][1][1]);
    b[5] |= (dig[py][3][1] | dig[pz][1][1]);
    b[7] |= dig[pz][3][1];
  }
  for (int i = 0; i < h; i++) {
    if (b[i] != a[i][pos]) {
      return false;
    }
  }
  return true;
}

void solve() {
  for (int i = 0; i <= n; i++) {
    for (int x = 0; x < d; x++) {
      for (int y = 0; y < d; y++) {
        for (int carry = 0; carry < 2; carry++) {
          dp[i][x][y][carry] = -1;
        }
      }
    }
  }
  dp[0][0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < d; x++) {
      for (int y = 0; y < d; y++) {
        bool found = false;
        for (int px = 0; px < d && !found; px++) {
          for (int py = 0; py < d && !found; py++) {
            for (int pcarry = 0; pcarry < 2 && !found; pcarry++) {
              if (dp[i][px][py][pcarry] == -1) {
                continue;
              }
              int pz = dp[i][px][py][pcarry];
              int z = x + y + pcarry;
              int carry = z / d;
              z %= d;
              if (good(i, x, y, z, px, py, pz)) {
                dp[i + 1][x][y][carry] = z;
                p[i + 1][x][y][carry][0] = px;
                p[i + 1][x][y][carry][1] = py;
                p[i + 1][x][y][carry][2] = pcarry;
                found = true;
              }
            }
          }
        }
      }
    }
  }
  int x = -1, y = -1, carry = 0;
  for (int xx = 0; xx < d; xx++) {
    for (int yy = 0; yy < d; yy++) {
      if (dp[n][xx][yy][carry] != -1 && ((dig[xx][1][1] == a[1][n]) && ((dig[xx][3][1] | dig[yy][1][1]) == a[3][n]) &&
                                         ((dig[yy][3][1] | dig[dp[n][xx][yy][carry]][1][1]) == a[5][n]) &&
                                         (dig[dp[n][xx][yy][carry]][3][1] == a[7][n]))) {
        x = xx;
        y = yy;
      }
    }
  }
  if (x == -1) {
    printf("NO\n");
    return;
  }
  for (int i = n; i > 0; i--) {
    ans[0][i - 1] = x;
    ans[1][i - 1] = y;
    ans[2][i - 1] = dp[i][x][y][carry];
    int px = p[i][x][y][carry][0];
    int py = p[i][x][y][carry][1];
    int pcarry = p[i][x][y][carry][2];
    x = px;
    y = py;
    carry = pcarry;
  }
  for (int i = 0; i < 3; i++) {
    reverse(ans[i], ans[i] + n);
    for (int j = 0; j < n; j++) {
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }
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
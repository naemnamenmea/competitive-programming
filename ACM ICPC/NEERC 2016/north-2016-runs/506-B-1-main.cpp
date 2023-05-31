#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define TASK "boysgirls"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;

void precalc() {
}

const int maxn = (int) 1e5 + 10;

int n, x, y;

int read() {
  if (scanf("%d%d%d", &n, &x, &y) < 3) {
    return 0;
  }
  return 1;
}

bool solve2() {
  int c = (x + y - n);
  if (c & 1) {
    return 0;
  }
  c /= 2;
  if (c < 0) {
    return 0;
  }
  int a = x - c, b = y - c;
  if (a < c || b < c) {
    return 0;
  }
  if (a + b != n) {
    return 0;
  }
  
  int k = 1 + !(n & 1);
  int ss[k], cs[k];
  if (k == 1) {
    ss[0] = n, cs[0] = c;
  } else {
    ss[0] = n / 2, cs[0] = c / 2;
    ss[1] = n / 2, cs[1] = (c + 1) / 2;
  }
  
  for (int i = 0; i < k; ++i) {
    if (cs[i] > ss[i]) {
      return 0;
    }
  }
  eprintf("k = %d, vals = {%d,%d}\n", k, a, b);
  for (int i = 0; i < k; ++i) {
    eprintf("%d,%d\n", ss[i], cs[i]);
  }
  
  for (int mask = 0; mask < (1 << k); ++mask) {
    vector<int> ans[k];
    
    int left[2] = {a, b};
    
    bool fail = 0;
    
    for (int i = 0; !fail && i < k; ++i) {
      if (cs[i] == 0) {
        int who = ((mask >> i) & 1);
        left[who] -= ss[i];
        if (left[who] < 0) {
          fail = 1;
          break;
        }
        ans[i] = vector<int>(ss[i], who);
      } else {
        for (int j = 0; !fail && j < cs[i]; ++j) {
          for (int who = 0; who < 2; ++who) {
            --left[who];
            ans[i].pb(who);
            if (left[who] < 0 || sz(ans[i]) > ss[i]) {
              fail = 1;
              break;
            }
          }
        }
      }
    }
    if (fail) {
      continue;
    }
    eprintf("!\n");
    for (int who = 0; who < 2; ++who) {
      if (!left[who]) {
        continue;
      }
      int i, pos;
      for (i = 0; i < k; ++i) {
        pos = find(ans[i].begin(), ans[i].end(), who) - ans[i].begin();
        if (pos == sz(ans[i])) {
          continue;
        }
        
        int cur = min(ss[i] - sz(ans[i]), left[who]);
        left[who] -= cur;
        ans[i].resize(sz(ans[i]) + cur);
        for (int j = sz(ans[i]) - 1; j > pos; --j) {
          if (j - cur > pos) {
            ans[i][j] = ans[i][j - cur];
          } else {
            ans[i][j] = who;
          }
        }
      }
      
      if (left[who]) {
        fail = 1;
        break;
      }
    }
    if (fail) {
      continue;
    }
    
    string res(n, '-');
    for (int r = 0; r < k; ++r) {
      for (int i = r, it = 0; it < ss[r]; ++it, i = ((i + 2) % n)) {
        res[i] = ans[r][it] ? 'G' : 'B';
      }
    }
    printf("%s\n", res.c_str());
    return 1;
  }
  return 0;
}

void solve() {
  if (!solve2()) {
    printf("Impossible\n");
    return;
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
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

const int k = 2;

const int maxn = 61 + 1;

map<pair<vector<int>, vector<int> >, int> mem;

int get(vector<int> lens, vector<int> a, bool refl = 1) {
  int n0 = sz(a);
  int n = 0;
  for (int i = 0; i < n0; ++i) {
    if (lens[i] == 0) {
      continue;
    }
    if (n && a[i] == a[n - 1]) {
      lens[n - 1] += lens[i];
    } else {
      lens[n] = lens[i];
      a[n++] = a[i];
    }
  }
  lens.resize(n);
  a.resize(n);
  assert(n > 0);
  
  int pos = max_element(a.begin(), a.end()) - a.begin();
  if (a[pos] == 0) {
    return 0;
  }
  
  if (n > k) {
    return inf;
  }

  const auto &key = mp(lens, a);
  {
    auto iter = mem.find(key);
    if (iter != mem.end()) {
      return iter->second;
    }
  }
    
  int res = inf;

  if (refl && n == 1) {
    res = min(res, get(a, lens, 0));
  }
  int bests = -1;
  for (int s = 1; s <= a[pos] && s <= lens[pos]; ++s) {
    vector<int> b = a, blens = lens;
    b.insert(b.begin() + pos, a[pos] - s);
    blens.insert(blens.begin() + pos, s);
    blens[pos + 1] -= s;
    /*for (int i = 0; i < n; i++) {
      eprintf("%d ", a[i]);
    }
    eprintf("\n");
    for (int i = 0; i <= n; i++) {
      eprintf("%d ", b[i]);
    }
    eprintf("\n");
    for (int i = 0; i < n; i++) {
      eprintf("%d ", lens[i]);
    }
    eprintf("\n");
    for (int i = 0; i <= n; i++) {
      eprintf("%d ", blens[i]);
    }
    eprintf("\n");
    eprintf("\n");*/
    int cur = get(blens, b) + 1;
    if (cur < res) {
      res = cur;
      bests = s;
    }
  }
  //eprintf("bests = %d\n", bests);
  if (refl && n == 1) {
    mem[mp(a, lens)] = min(mem[mp(a, lens)], res);
  }
  /*for (int i = 0; i < n; i++) {
    eprintf("%d ", a[i]);
  } 
  eprintf("\n");
  for (int i = 0; i < n; i++) {
    eprintf("%d ", lens[i]);
  } 
  eprintf("\n");
  eprintf("%d\n\n", res);*/
  mem[key] = res;
  return res;
}
 
int dp[maxn][maxn];

void precalc() {
  mem.clear();
  if (1) {
    return;
  }
  for (int w = 1; w < maxn; ++w) {
    for (int h = 1; h < maxn; ++h) {
      int &cur = dp[w][h];
      cur = get({w}, {h});
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

int get2(vector<int> lens, vector<int> a, bool refl, int dx, int dy, int rev) {
  int n0 = sz(a);
  int n = 0;
  for (int i = 0; i < n0; ++i) {
    if (lens[i] == 0) {
      continue;
    }
    if (n && a[i] == a[n - 1]) {
      lens[n - 1] += lens[i];
    } else {
      lens[n] = lens[i];
      a[n++] = a[i];
    }
  }
  lens.resize(n);
  a.resize(n);
  assert(n > 0);
  
  int pos = max_element(a.begin(), a.end()) - a.begin();
  if (a[pos] == 0) {
    return 0;
  }
  
  if (n > k) {
    return inf;
  }

  const auto &key = mp(lens, a);
  int res = mem[key];

  int bests = -1;
  for (int s = 1; s <= a[pos] && s <= lens[pos]; ++s) {
    vector<int> b = a, blens = lens;
    b.insert(b.begin() + pos, a[pos] - s);
    blens.insert(blens.begin() + pos, s);
    blens[pos + 1] -= s;
    int cur = get(blens, b, 1) + 1;
    if (res == cur) {
      int sum = accumulate(lens.begin(), lens.begin() + pos, 0);
      if (!rev) {
        printf("%d %d %d\n", dx + sum, dy + a[pos] - s, s);
      } else {
        printf("%d %d %d\n", dx + a[pos] - s, dy + sum, s);
      }
      get2(blens, b, 1, dx, dy, rev);
      return res;
    }
  }
  if (refl && n == 1) {
    if (res == get(a, lens, 0)) {
      get2(a, lens, 0, dx, dy, !rev);
      return res;
    }
  }
  assert(0);
}

void solve() {
  printf("%d\n", get({w}, {h}));
  get2({w}, {h}, 1, 0, 0, 0);
}

int main() {
  precalc();  
  get({59}, {61});
  exit(0);
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
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define TASK "gangsters"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;

void precalc() {
}

const int maxn = (int) 1e5 + 10, maxl = 17;

int n, q;
int pr[maxl][maxn];

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d", pr[0] + i);
    --pr[0][i];
  }
  return 1;
}

vector<vector<int> > es;

int dp[maxn];
int ts[maxn];

int tme;
int start[maxn];

int depth[maxn];

void dfs(int v, int t0) {
  ts[v] = t0;
  dp[v] = !sz(es[v]);
  start[v] = tme++;
  for (int it = 0; it < sz(es[v]); ++it) {
    int u = es[v][it];
    depth[u] = depth[v] + 1;
    dfs(u, t0 == -1 ? it : t0);
    dp[v] += dp[u];
  }
}

int lca(int s, int t) {
  if (depth[s] < depth[t]) {
    swap(s, t);
  }
  
  for (int it = maxl - 1; it >= 0; --it) {
    if (depth[s] - (1 << it) >= depth[t]) {
      s = pr[it][s];
    }
  }
  
  if (s == t) {
    return s;
  }
  
  for (int it = maxl - 1; it >= 0; --it) {
    if (pr[it][s] != pr[it][t]) {
     s = pr[it][s], t = pr[it][t];
    }
  }
  
  return pr[0][s];
}

pair<int, int> get(const set<pair<int, int> > &cur) {
  if (!sz(cur)) {
    return mp(0, 0);
  }
  
  int a = cur.begin()->second;
  int b = cur.rbegin()->second;
  
  int g = lca(a, b);
  
  return mp(1, dp[g]);
}  
  

void solve() {
  for (int it = 1; it < maxl; ++it) {
    for (int i = 0; i < n; ++i) {
      pr[it][i] = pr[it - 1][pr[it - 1][i]];
    }
  }
  
  es = vector<vector<int> >(n);
  for (int i = 1; i < n; ++i) {
    es[pr[0][i]].pb(i);
  }
  
  vector<set<pair<int, int> > > trees(sz(es[0]));
  
  depth[0] = 0;
  tme = 0;
  dfs(0, -1);
  
  int alife = 0;
  
  pair<int, int> res(0, 0);
  for (int iter = 0; iter < q; ++iter) {
    char ch;
    int x;
    scanf(" %c%d", &ch, &x);
    --x;
    
    int t = ts[x];
    {
      auto got = get(trees[t]);
      res.first -= got.first, res.second -= got.second;
    }
    
    if (ch == '+') {
      ++alife;
      trees[t].insert(mp(start[x], x));
    } else {
      --alife;
      trees[t].erase(mp(start[x], x));
    }
    
    {
      auto got = get(trees[t]);
      res.first += got.first, res.second += got.second;
    }
    printf("%d %d\n", res.first, res.second - alife);
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
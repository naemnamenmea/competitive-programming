#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <bitset>
#include <cassert>
#include <cmath>
#include <algorithm>

using namespace std;

#define FILE_NAME "gangsters"

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vii;

#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; --i)
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define snd second

const int MAXN = 4e5 + 10;
const int INF = 1e9;

struct SegmTree {
  vii t;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    t.assign(sz * 2, mp(INF, 0));
  }

  pii get_min(int l, int r) {
    assert(l < sz(t));
    l += sz;
    r += sz;
    pii res = mp(INF, 0);
    while (l <= r) {
      if  (l & 1) {
        res = min(res, t[l]);
      }
      if  (~r & 1) {
        res = min(res, t[r]);
      }
      l = (l + 1) >> 1;
      r = (r - 1) >> 1;
    }
    return res;
  }

  void put(int p, int val) {
    int v = p + sz;
    t[v] = mp(val, p);
    v >>= 1;
    while (v) {
      t[v] = min(t[v * 2], t[v * 2 + 1]);
      v >>= 1;
    }
  }        
};

int n, q;
vi g[MAXN];

bool read() {
  if  (scanf("%d%d", &n, &q) < 2) {
    return 0;
  }
  forn(i, n) {
    g[i].clear();
  }
  forn(i, n - 1) {
    int p;
    scanf("%d", &p);
    --p;
    g[p].pb(i + 1);
  }
  return 1;
}

int depth[MAXN];
vi order;
int pos[MAXN];
vi sons;
set<int> alive[MAXN];
int id_son[MAXN];
int sz[MAXN];
SegmTree T;

void dfs(int v, int de) {
  depth[v] = de;
  order.pb(v);
  sz[v] = g[v].empty();
  for (int to : g[v]) {
    order.pb(v);
    dfs(to, de + 1);
    sz[v] += sz[to];
  }
  order.pb(v);
}

void dfs2(int v, int id) {
  id_son[v] = id;
  for (int to : g[v]) {
    dfs2(to, id);
  }
}

void calc(int id, int& ans_e, int& ans_v, int coef) {
  int E = 0;
  int V = 0;
  if  (!alive[id].empty()) {  
    int l = *alive[id].begin();
    int r = *alive[id].rbegin();
    pii mn = T.get_min(l, r);
    assert(mn.snd != -1);
    int lc = order[mn.snd];
    E = 1;
    assert(depth[lc] == mn.first);
//    printf("lc = %d\n", lc);
    V = sz[lc] - sz(alive[id]);
//    printf("V = %d\n", V);
  }
  ans_e += coef * E;
  ans_v += coef * V;
}

void solve() {
  dfs(0, 0);

  ford(i, sz(order)) {
    pos[order[i]] = i;
  }

  T = SegmTree(sz(order));
  forn(i, sz(order)) {
    T.put(i, depth[order[i]]);
  }

  for (int s : g[0]) {
    dfs2(s, sz(sons));
    sons.pb(s);
  }

  int ans_e = 0;
  int ans_v = 0;
  scanf("\n");
  forn(i, q) {
    char t = getchar();
    int v;
    scanf("%d\n", &v);
    --v;
    int id = id_son[v];
//    printf("v=%d, id=%d\n", v, id);
    calc(id, ans_e, ans_v, -1);
    if  (t == '+') {
      alive[id].insert(pos[v]);    
    } else {
      assert(t == '-');
      alive[id].erase(pos[v]);
    }
    calc(id, ans_e, ans_v, +1);
    printf("%d %d\n", ans_e, ans_v); 
  }
}

int main() {
  freopen(FILE_NAME ".in", "r", stdin);
  freopen(FILE_NAME ".out", "w", stdout);

  while (read()) {
    solve();
  }

  return 0;
}

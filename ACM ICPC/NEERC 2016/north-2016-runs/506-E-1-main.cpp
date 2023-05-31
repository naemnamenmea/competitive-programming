#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define TASK "easy"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;

const int ps[2] = {(int) 1e9 + 7, (int) 1e9 + 9};

struct Hash {
  const static int n = 2;
  int a[n];
  
  Hash(long long x = 0) {
    for (int i = 0; i < n; ++i) {
      a[i] = x % ps[i];
      if (a[i] < 0) {
        a[i] += ps[i];
      }
    }
  }

  Hash operator + (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; ++i) {
      res.a[i] = a[i] + h.a[i];
      if (res.a[i] >= ps[i]) {
        res.a[i] -= ps[i];
      }
    }
    return res;
  }
  
  Hash operator - (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; ++i) {
      res.a[i] = a[i] - h.a[i];
      if (res.a[i] < 0) {
        res.a[i] += ps[i];
      }
    }
    return res;
  }
  
  Hash operator * (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; ++i) {
      res.a[i] = (long long) a[i] * h.a[i] % ps[i];
    }
    return res;
  }
  
  Hash operator ^ (long long pw) const {
    Hash res(1);
    Hash x = *this;
    for (; pw; pw >>= 1) {
      if (pw & 1) {
        res = res * x;
      }
      x = x * x;
    }
    return res;
  }
  
  
  bool operator == (const Hash &h) const {
    return a[0] == h.a[0] && a[1] == h.a[1];
  }
};

Hash q;

void precalc() {
  q = 239017 + rand() % 1000;
}

const int maxn = (int) 1e5 + 10;
char s[maxn];

string sq[maxn];

int len, w, h;

int read() {
  if (scanf("%d", &len) < 1) {
    return 0;
  }
  gets(s);
  gets(s);
  assert((int) strlen(s) == len);
  
  scanf("%d%d", &w, &h);
  for (int i = 0; i < w; ++i) {
    cin >> sq[i];
  }
  return 1;
}

const long long K = maxn * 5;

const int gox[4] = {1, 0, -1, 0}, goy[4] = {0, 1, 0, -1};
const char goch[] = "drul";

void solve() {
  Hash desire = 0;
  long long was = -1;
  
  int needc = 0;
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      if (sq[i][j] == 'X') {
        ++needc;
        if (was == -1) {
          was = i * K + j;
        }
        desire = desire + (q ^ (i * K + j - was));
      }
    }
  }
  
  set<pair<pair<int, int>, int> > tree;
  int xl = maxn, yl = maxn, xr = xl, yr = yl;
  
  tree.insert(mp(mp(xl, yl), 1));
  Hash curh = (q ^ (xl * K + yl));
  
  for (int l = 0, r = 0; l < len; ++l) {
    /*eprintf("l = %d, r = %d\n", l, r);
    Hash ncurh = 0;
    for (auto cur : tree) {
      eprintf("#(%d,%d) = %d\n", cur.first.first - maxn, cur.first.second - maxn, cur.second);
      assert(cur.second);
      ncurh = ncurh + (q ^ (cur.first.first * K + cur.first.second));
    }
    assert(curh == ncurh);
    assert(l <= r);
    */
    for (; sz(tree) < needc && r < len; ++r) {
      int dir = find(goch, goch + 4, s[r]) - goch;
      if (dir < 4) {
        xr += gox[dir], yr += goy[dir];
        
        auto iter = tree.lower_bound(mp(mp(xr, yr), -inf));
        int k = 0;
        if (iter != tree.end() && iter->first == mp(xr, yr)) {
          k = iter->second;
          tree.erase(iter);
        }
        if (!k) {
          curh = curh + (q ^ (xr * K + yr));
        }
        tree.insert(mp(mp(xr, yr), k + 1));  
      }
    }
    
    if (sz(tree) == needc) {
      auto mn = tree.begin()->first;
      if (curh == ((q ^ (mn.first * K + mn.second)) * desire)) {
        printf("YES\n%d %d\n", l + 1, r);
        return;
      }
    }
    
    int dir = find(goch, goch + 4, s[l]) - goch;
    if (dir < 4) {
      auto iter = tree.lower_bound(mp(mp(xl, yl), -inf));
      int k = 0;
      if (iter != tree.end() && iter->first == mp(xl, yl)) {
        k = iter->second;
        tree.erase(iter);
      }
      assert(k > 0);
      if (k == 1) {
        curh = curh - (q ^ (xl * K + yl));
      }
      if (k > 1) {
        tree.insert(mp(mp(xl, yl), k - 1));
      }
      
      xl += gox[dir], yl += goy[dir];
    }
  }
  printf("NO\n");
}

int main() {
  srand(23);
  //srand(time(0));
  
  precalc();  
  freopen(TASK ".out", "w", stdout);
  freopen(TASK ".in", "r", stdin);
  
  while (read()) {
    solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}
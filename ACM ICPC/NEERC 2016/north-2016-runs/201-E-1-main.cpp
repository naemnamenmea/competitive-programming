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
#include <cstring>

using namespace std;

#define FILE_NAME "easy"

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; --i)
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define fst first
#define snd second
#define next next_____
#define prev prev_______

const int MOD[2] = {(int) 1e9 + 7, (int) 1e9 + 9};
const int PP = 3;
const int QQ = 5;
const int MAXN = 1e5 + 10;

void add(int& x, int y, int m) {
  ((x += y) >= m) && (x -= m);
}

int mul(int x, int y, int m) {
  return x * 1ll * y % m;
}

int mpow(int a, int p, int m) {
  int res = 1;
  for (; p > 0; p /= 2, a = mul(a, a, m)) {
    if (p & 1) {
      res = mul(res, a, m);
    }
  }
  return res;
}

struct Hash {
  static const int S = 2;
  int v[S];

  Hash(int x = 0) {
    forn(i, S) v[i] = x % MOD[i];
  }

  Hash& operator += (const Hash& h) {
    forn(i, S) {
      add(v[i], h.v[i], MOD[i]);
    }
    return *this;
  }

  Hash& operator -= (const Hash& h) {
    forn(i, S) {
      add(v[i], -h.v[i] + MOD[i], MOD[i]);
    }
    return *this;
  }

  Hash& operator *= (const Hash& h) {
    forn(i, S) {
      v[i] = mul(v[i], h.v[i], MOD[i]);
    }
    return *this;
  }

  bool operator == (const Hash& h) const {
    forn(i, S) {
      if  (v[i] != h.v[i]) {
        return 0;
      }
    }
    return 1;
  }

  void print() const {
    printf("%d %d\n", v[0], v[1]);
  }
};

Hash operator + (const Hash& l, const Hash& r) {
  Hash t = l;
  t += r;
  return t;
}

Hash operator * (const Hash& l, const Hash& r) {
  Hash t = l;
  t *= r;
  return t;
}

Hash inv(const Hash& h) {
  Hash r;
  forn(i, Hash::S) {
    r.v[i] = mpow(h.v[i], MOD[i] - 2, MOD[i]);
  }
  assert(h * r == 1);
  return r;
}

Hash P[MAXN];
Hash Q[MAXN];
Hash inv_P[MAXN];
Hash inv_Q[MAXN];

void precalc() {
  P[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    P[i] = P[i - 1] * PP;
  }

  Q[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    Q[i] = Q[i - 1] * QQ;
  }

  forn(i, MAXN) {
    inv_P[i] = inv(P[i]);
    inv_Q[i] = inv(Q[i]);
  }
}

Hash pow_P(int p) {
  if (p < 0) {
    return inv_P[-p];
  }
  return P[p];
}

Hash pow_Q(int p) {
  if (p < 0) {
    return inv_Q[-p];
  }
  return Q[p];
}


const int dx[4] = { 0, +1, 0, -1 };
const int dy[4] = { -1, 0, +1, 0 };

int l, n, m;
int dir[MAXN];
int num[MAXN];
vector<vi> a;

bool read() {
  if  (scanf("%d\n", &l) < 1) {
    return 0;
  }
  static char t[MAXN];
  gets(t);
  l = 0;
//  printf("len = %d\n", strlen(t));
//  puts(t);
  for (int i = 0; t[i]; ++i) {
    if  (t[i] == 'u') {
      dir[l] = 0;
      num[l++] = i;
    }
    if  (t[i] == 'r') {
      dir[l] = 1;
      num[l++] = i;
    }
    if  (t[i] == 'd') {
      dir[l] = 2;
      num[l++] = i;
    }
    if  (t[i] == 'l') {
      dir[l] = 3;
      num[l++] = i;
    }
  }
  scanf("%d%d\n", &n, &m);
  a.resize(n);
  forn(i, n) {
    scanf("%s\n", t);
    forn(j, m) {
      a[i].pb(t[j] == 'X');
    }
  }
  return 1;
}

pii p[MAXN];
int prev[MAXN];
int next[MAXN];

bool solve() {
  Hash H;
  int CNT = 0;
  {
    int min_x = MAXN;
    int min_y = MAXN;
    forn(i, n) forn(j, m) {
      if  (a[i][j]) {
        min_x = min(min_x, j);
        min_y = min(min_y, i);
      }
    }
    forn(i, n) forn(j, m) {
      if  (a[i][j]) {
        H += P[i - min_y] * Q[j - min_x];
        ++CNT;
      }
    }
  }
//  printf("H:\n");
//  H.print();

  pii point(0, 0);
  forn(i, l + 1) {
    p[i] = point;
    point.fst += dx[dir[i]];
    point.snd += dy[dir[i]];
  }

  {
    memset (prev, -1, sizeof prev);
    map<pii, int> pos;
    forn(i, l + 1) {
      if  (pos.count(p[i])) {
        prev[i] = pos[p[i]];
      }
      pos[p[i]] = i;
    }

    memset (next, -1, sizeof next);
    pos.clear();
    ford(i, l + 1) {
      if  (pos.count(p[i])) {
        next[i] = pos[p[i]];
      }
      pos[p[i]] = i;
    }
  }

//  printf("points:\n");
//  forn(i, l + 1) {
//    printf("%d %d, next=%d, prev=%d\n", p[i].fst, p[i].snd, next[i], prev[i]);
//  }

  multiset<int> X;
  multiset<int> Y;
  int cnt = 0;
  int R = 0;
  Hash hash;
  forn(L, l + 1) {
    while (R < l + 1 && cnt < CNT) {
      if  (prev[R] < L) {
        hash += pow_P(p[R].snd) * pow_Q(p[R].fst);
        X.insert(p[R].fst);
        Y.insert(p[R].snd);    
        ++cnt;   
//        printf("add %d\n", R);
      }
      ++R;
    }

    if  (cnt < CNT) {
      return 0;
    }

    int min_x = *X.begin();
    int min_y = *Y.begin();

    Hash cur_hash = hash * pow_P(-min_y) * pow_Q(-min_x);

//    printf("check\n");
//    cur_hash.print();
    if  (cur_hash == H) {
      puts("YES");
      printf("%d %d\n", num[L] + 1, num[R - 2] + 1);
      return 1;
    }

    if  (next[L] >= R || next[L] == -1) {
      --cnt;
      hash -= pow_P(p[L].snd) * pow_Q(p[L].fst);
      X.erase(X.find(p[L].fst));
      Y.erase(Y.find(p[L].snd));
//      printf("del %d\n", L);
    }
  }

  return 0;
}

int main() {
  freopen(FILE_NAME ".in", "r", stdin);
  freopen(FILE_NAME ".out", "w", stdout);

  precalc();

  while (read()) {
    if (!solve()) {
      puts("NO");
    }
    break;
  }

  return 0;
}

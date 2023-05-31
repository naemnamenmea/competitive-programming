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

#define FILE_NAME "digital"

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
#define prev prev______

const int MAXN = 100 + 10;

int dig[10][5];
int w;
int A[9][MAXN];

bool read() {
  if  (scanf("%d", &w) < 1) {
    return 0;
  }
  forn(i, 9) {
    forn(j, w) {
      scanf("%d", &A[i][j]);
    }
    if  (i & 1) {
      scanf("%d", &A[i][w]);
    }
  }
  return 1;
}

void precalc() {
  dig[0][0] = (1 << 0);
  dig[0][1] = (1 << 0) + (1 << 1);
  dig[0][2] = 0;
  dig[0][3] = (1 << 0) + (1 << 1);
  dig[0][4] = (1 << 0);

  dig[1][0] = 0;
  dig[1][1] = 2;
  dig[1][2] = 0;
  dig[1][3] = 2;
  dig[1][4] = 0;

  dig[2][0] = 1;
  dig[2][1] = 2;
  dig[2][2] = 1;
  dig[2][3] = 1;
  dig[2][4] = 1;

  dig[3][0] = 1;
  dig[3][1] = 2;
  dig[3][2] = 1;
  dig[3][3] = 2;
  dig[3][4] = 1;

  dig[4][0] = 0;
  dig[4][1] = 3;
  dig[4][2] = 1;
  dig[4][3] = 2;
  dig[4][4] = 0;

  dig[5][0] = 1;
  dig[5][1] = 1;
  dig[5][2] = 1;
  dig[5][3] = 2;
  dig[5][4] = 1;

  dig[6][0] = 1;
  dig[6][1] = 1;
  dig[6][2] = 1;
  dig[6][3] = 3;
  dig[6][4] = 1;

  dig[7][0] = 1;
  dig[7][1] = 2;
  dig[7][2] = 0;
  dig[7][3] = 2;
  dig[7][4] = 0;

  dig[8][0] = 1;
  dig[8][1] = 3;
  dig[8][2] = 1;
  dig[8][3] = 3;
  dig[8][4] = 1;

  dig[9][0] = 1;
  dig[9][1] = 3;
  dig[9][2] = 1;
  dig[9][3] = 2;
  dig[9][4] = 1;
}     

struct Prev {
  int i, mask, r, a, b, c;
};

bool bit(int mask, int i) {
  return (mask >> i) & 1;
}

bool dp[MAXN][1 << 9][3];
Prev prev[MAXN][1 << 9][3];

void restore(int i, int mask, int r, vi& a, vi& b, vi& c) {
  if  (i == w) {
    return;
  }
  a.pb(prev[i][mask][r].a);
  b.pb(prev[i][mask][r].b);
  c.pb(prev[i][mask][r].c);
  restore(prev[i][mask][r].i, prev[i][mask][r].mask, prev[i][mask][r].r, a, b, c);
}

bool solve() {
  memset (dp, 0, sizeof dp);
  dp[w][0][0] = 1;
  for (int i = w; i > 0; --i) {
    forn(mask, 1 << 9) {
      bool bad = false;
      for (int j = 0; j < 9; j += 2) {
        if  (bit(mask, j)) {
          bad = true;
          break;
        }
      }
      if  (bad) {
        continue;
      }
      forn(r, 2) {
        if (!dp[i][mask][r]) {
          continue;
        }
//        cout << "i=" << i << ", mask=" << bitset<9>(mask) << ", r=" << r << endl;
        forn(a, 10) forn(b, 10) {
          // ---------------------<
          /*
          if  (i == 2 && !(a == 7 && b == 4)) {
            continue;
          }
          if  (i == 1 && !(a == 3 && b == 3)) {
            continue;
          }
          */
          int c = (a + b + r) % 10;
          int nr = (a + b + r) / 10;
          assert(nr <= 1);

        //  printf("a=%d, b=%d, c=%d\n", a, b, c);

          int right_mask = mask;
          // a
          if  (bit(dig[a][1], 1)) {
            right_mask |= 1 << 1;
          }
          if  (bit(dig[a][3], 1)) {
            right_mask |= 1 << 3;
          }

          // b
          if  (bit(dig[b][1], 1)) {
            right_mask |= 1 << 3;
          }
          if  (bit(dig[b][3], 1)) {
            right_mask |= 1 << 5;  
          }
          
          // c
          if  (bit(dig[c][1], 1)) {
            right_mask |= 1 << 5;
          }
          if  (bit(dig[c][3], 1)) {
            right_mask |= 1 << 7;
          }

          int need_right_mask = 0;
          for (int j = 1; j < 9; j += 2) {
            if  (A[j][i]) {
              need_right_mask |= 1 << j;
            }
          }

//          printf("a=%d, b=%d, c=%d\n", a, b, c);
//          cout << bitset<9>(right_mask) << " " << bitset<9>(need_right_mask) << endl;
          if  (right_mask != need_right_mask) {
            continue;
          }

          int z0 = A[0][i - 1];
          int zz0 = bit(dig[a][0], 0);
          if  (z0 != zz0) {
            continue;
          }

          int z2 = A[2][i - 1];
          int zz2 = bit(dig[a][2], 0) | bit(dig[b][0], 0);
          if  (z2 != zz2) {
            continue;
          }

//          cerr << "z2" << endl;

          int z4 = A[4][i - 1];
          int zz4 = bit(dig[b][2], 0) | bit(dig[c][0], 0) | bit(dig[a][4], 0);
          if  (z4 != zz4) {
            continue;
          }

//          cerr << "z4" << endl;

          int z6 = A[6][i - 1];
          int zz6 = bit(dig[c][2], 0) | bit(dig[b][4], 0);
          if  (z6 != zz6) {
            continue;
          }

//          cerr << "z6" << endl;

          int z8 = A[8][i - 1];
          int zz8 = bit(dig[c][4], 0);
          if  (z8 != zz8) {
            continue;
          }

//          cerr << "z8" << endl;

          int nmask = 0;
          {
            // a
            if  (bit(dig[a][1], 0)) {
              nmask |= 1 << 1;
            }
            if  (bit(dig[a][3], 0)) {
              nmask |= 1 << 3;
            }

            // b
            if  (bit(dig[b][1], 0)) {
              nmask |= 1 << 3;
            }
            if  (bit(dig[b][3], 0)) {
              nmask |= 1 << 5;  
            }
            
            // c
            if  (bit(dig[c][1], 0)) {
              nmask |= 1 << 5;
            }
            if  (bit(dig[c][3], 0)) {
              nmask |= 1 << 7;
            }
          }

          /*
          printf("i=%d, a=%d, b=%d\n", i, a, b);
          cout << "nmask = ";
          cout << bitset<9>(nmask);
          cout << endl;
          */

          dp[i - 1][nmask][nr] = true;
          prev[i - 1][nmask][nr] = Prev{i, mask, r, a, b, c};
        }
      }
    }
  }

  int need_mask = 0;
  for (int i = 1; i < 9; i += 2) {
    if  (A[i][0]) {
      need_mask |= 1 << i;
    }
  }

  if  (!dp[0][need_mask][0]) {
    return false;
  }

  vi a;
  vi b;
  vi c;
  restore(0, need_mask, 0, a, b, c);
  for (auto x : a) printf("%d", x);
  puts("");
  for (auto x : b) printf("%d", x);
  puts("");
  for (auto x : c) printf("%d", x);
  puts("");
  return true;
}

int main() {
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);

  precalc();

  while (read()) {
    if  (!solve()) {
      puts("NO");
    }
  }

  return 0;
}

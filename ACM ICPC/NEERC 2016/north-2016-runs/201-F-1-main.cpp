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

#define FILE_NAME "folding"

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

int W, H, w, h;

bool read() {
  if  (scanf("%d%d%d%d", &W, &H, &w, &h) < 4) {
    return 0;
  }
  return 1;
}

int go(int A, int a) {
  if  (A < a) {
    return -1;
  }
  if  (a == A) {
    return 0;
  }
  if  (a >= (A + 1) / 2) {
    return 1;
  }
  return 1 + go((A + 1) / 2, a);
}

int solve() {
  int ans = -1;
  forn(it, 2) {
    int ans1 = go(W, w);
    int ans2 = go(H, h);
    if  (ans1 != -1 && ans2 != -1) {
      int cur = ans1 + ans2;
      if  (ans == -1 || cur < ans) {
        ans = cur;
      }
    }
    swap(w, h);
  }
  return ans;
}

int main() {
  freopen(FILE_NAME ".in", "r", stdin);
  freopen(FILE_NAME ".out", "w", stdout);

  while (read()) {
    printf("%d\n", solve());
  }

  return 0;
}

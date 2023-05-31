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

#define FILE_NAME "anniversary"

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

int w, h;
int a_x, a_y;
int b_x, b_y;

bool read() {
  if  (scanf("%d%d", &w, &h) < 2) {
    return 0;
  }
  scanf("%d%d", &a_x, &a_y);
  scanf("%d%d", &b_x, &b_y);
  return 1;
}

void solve() {
  if  (a_x != b_x) {
    printf("%d %d %d %d\n", a_x, 0, b_x, h);
  } else {
    printf("%d %d %d %d\n", 0, a_y, w, b_y);
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

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

#define FILE_NAME "integral"

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

int n;

const int maxn = 200005;
int x[maxn], y[maxn];
int psum[maxn];
bool read() {
  if  (scanf("%d", &n) < 1) {

    return 0;
  }
  for (int i =0; i < n; i++)     
  {
     scanf("%d%d", &x[i], &y[i]);
     x[i] = (x[i] + (int)1e9) % 2;
     y[i] = (y[i] + (int)1e9) % 2;
  }

  return 1;
}

ll cnt[2][2][2];

void solve() {
  int allsum = 0;

  psum[0] = 0;
  x[n] = x[0]; y[n] = y[0];
  for (int i = 0; i < n; i++)
  {
     psum[i+1] = (psum[i] + (x[i+1] + x[i]) * (y[i+1] + y[i])) % 2;
  }
  allsum = psum[n];
  if (allsum != 0)
  {
      cout << 0 << endl;
      return;
  }
  for (int i=  0; i < 2; i++)
     for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
           cnt[i][j][k] = 0;
  for (int i = 0; i < n; i++)
     cnt[x[i]][y[i]][psum[i]]++;
  ll ans = 0;
  for (int i1 = 0; i1 < 2; i1++)
  for (int j1 = 0; j1 < 2; j1++)
  for (int k1 = 0; k1 < 2; k1++)
  for (int i2 = 0; i2 < 2; i2++)
  for (int j2 = 0; j2 < 2; j2++)
  for (int k2 = 0; k2 < 2; k2++)
  {
     tuple<int,int,int> o1 = make_tuple(i1,j1,k1);
     tuple<int,int,int> o2 = make_tuple(i2,j2,k2);
     if (o1 > o2) continue;
     int odd = ((k2 + k1) + (i1+i2)*(j1+j2)) % 2;
     if (odd == 0)
     {
        if (o1 == o2)
        {
           ans += cnt[i1][j1][k1] * (cnt[i1][j1][k1] - 1ll) / 2ll;
        }
        else ans += cnt[i1][j1][k1] * cnt[i2][j2][k2];
     }

  }
  cout << ans - (ll)n << endl;

}

int main() {
  freopen(FILE_NAME ".in", "r", stdin);
  freopen(FILE_NAME ".out", "w", stdout);

  while (read()) {
    solve();
  }

  return 0;
}

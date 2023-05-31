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
#include <vector>

using namespace std;

#define FILE_NAME "codecoder"

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

bool read() {       
  if (cin >> n)
    return 1;
  return 0;
}

struct human
{
  int cf;
  int tc;
  int id;

  bool operator < (const human &r)
  {
    return cf < r.cf;
  }
};               
               
void solve() {
  vector<human> v(n);
  for (int i = 0; i < n; i++)
  {
    v[i].id = i;
    cin >> v[i].cf >> v[i].tc;
  }
  sort(all(v));

  vi max_tc(n);
  max_tc[0] = v[0].tc;
  for (int i = 1; i < n; i++)
    max_tc[i] = max(max_tc[i - 1], v[i].tc);

  vi dp(n);
  dp[n - 1] = n - 1;

  int r = n - 1;
  for (int i = n - 2; i >= 0; i--)
  {
    while (r >= 0 && v[r].tc > max_tc[i])
      r--;
    assert(r != -1);      

    if (r == i)
      dp[i] = i;
    else
      dp[i] = dp[r];
  }

  vi ans(n);
  for (int i = 0; i < n; i++)
    ans[v[i].id] = dp[i];

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i + 1 == n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
                          
  freopen(FILE_NAME ".in", "r", stdin);
  freopen(FILE_NAME ".out", "w", stdout);

  while (read()) {
    solve();
  }

  return 0;
}


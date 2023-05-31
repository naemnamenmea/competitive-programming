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

#define FILE_NAME "king"

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

struct date
{
  int d;
  int m;
  int y;

  bool operator < (const date &r) const
  {       
    if (y != r.y)
      return y < r.y;
    if (m != r.m)
      return m < r.m;
    return d < r.d;
  }
};

date king;

bool read_date (date &where)
{                     
  if (cin >> where.d >> where.m >> where.y)
    return true;
  return false;
}

bool read() {     
  if (!read_date(king))
    return 0;
  return 1;
}

void solve() {
  int n;
  cin >> n;

  vector<date> sons(n);
  for (int i = 0; i < n; i++)
    assert(read_date(sons[i]));

  int where = -1;
  for (int i = 0; i < n; i++)
  {
    date cur = sons[i];
    cur.y += 18;
                 
    if (!(king < cur))
    {                                          
      if (where == -1 || sons[where] < sons[i])
        where = i;
    } 
  }

  cout << (where == -1 ? -1 : where + 1) << endl;
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

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

#define FILE_NAME "boysgirls"

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

pii check (const string &s)
{
  int n = sz(s);
  assert(n >= 2);

  int nx = 0, ny = 0;
  for (int i = 0; i < n; i++)
  {
    int ni = (i == 0 ? n - 1 : i - 1);
    int pi = (i + 1 == n ? 0 : i + 1);
    if (s[ni] == 'B' || s[pi] == 'B')
      nx++;
    ny += (s[ni] == 'G' || s[pi] == 'G');
  }
  return mp(nx, ny);
}

string who (int g, int b, int g1, int b1, int G, int B)
{
    if (2 * g - b1 > B || 2 * g - g1 > G || b1 > g || g1 > g)
      return "";
    if (g == g1 && G != g)
      return "";
    if (g == b1 && B != g)
      return "";

    string ans;        

    int memg = g;
    for (int i = 0; i < 2 * memg; i++)
    {        
      if (i & 1)
      {
        if (g1 > 0)
          ans += "G", g1--, g--, G--;
        else if (g > 1)
          ans += "GG", g--, G -= 2;
        else if (g == 1)
        {
          assert(G >= 2);
          ans += string(G, 'G');
          g--, G = 0;
        }
        else
          assert(false);
      }
      else
      {   
        if (b1 > 0)
          ans += "B", b1--, b--, B--;
        else if (b > 1)
          ans += "BB", b--, B -= 2;
        else if (b == 1)
        {
          assert(B >= 2);
          ans += string(B, 'B');
          b--, B = 0;
        }
        else
          assert(false);
      }
  }

  return ans;
}

int n, x, y;

string brut_force ()
{
   vector<string> v(1, "");
   for (int i = 0; i < n; i++)
   {
    vector<string> nv;
    for (string s : v)
    {
      nv.pb(s + "B");
      nv.pb(s + "G");
    }

    v = nv;
   }

   for (const string &s : v)
   if (check(s) == mp(x, y))
    return s;
   return "";
}

bool read() {     
  if (cin >> n >> x >> y) 
    return 1;
  return 0;
}

string solve ()
{                   

  for (char ch : {'B', 'G'})
  if (check(string(n, ch)) == mp(x, y))
    return string(n, ch);

  if (x + y < n || (x + y - n) % 2 == 1)
    return "";

  for (int g_ = 1; g_ <= n / 2; g_++)
  {     
    int g = g_;

    int rt = (x + y - n);
    int gb1 = (4 * g - rt) / 2;
    if (gb1 < 0 || gb1 > 2 * g)
      continue;

    int B = x - 2 * g + gb1;
    int G = y - 2 * g + gb1;
    assert(B + G == n);
    if (B < g || G < g)
      continue;

    vi values;
    values.pb(0);
    values.pb(1);
    values.pb(gb1 - 1);
    values.pb(gb1);
    for (int vs : {B, G})
    for (int x = -1; x <= 1; x++)
      values.pb(2 * g - vs + x);

    for (int b1_ : values)
    for (int c = 0; c < 2; c++)
    if (0 <= b1_ && b1_ <= gb1)
    {              
      int b1 = (c ? gb1 - b1_ : b1_);
      int g1 = (c ? b1_ : gb1 - b1_);
                        
      string cur = who(g, g, g1, b1, G, B);
      if (sz(cur) == n)
      {
        assert(check(cur) == mp(x, y));
        return cur;
      }
    }
  }

  return "";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
                          
  freopen(FILE_NAME ".in", "r", stdin);
  freopen(FILE_NAME ".out", "w", stdout);

  //#define TEST

  #ifndef TEST
  while (read()) 
  #else
  for (n = 2; n <= 10; n++)
  for (x = 0; x <= n; x++)
  for (y = 0; y <= n; y++)
  #endif
  {
    string s = solve();
    #ifdef TEST
    if (!s.empty())
    {
      assert(sz(s) == n);
      assert(check(s) == mp(x, y));
    }
    else
    {
      cerr << n << ' ' << x << ' ' << y << endl;
      cerr << brut_force() << endl;
      assert(brut_force().empty());
    }
    #endif

    cout << (s.empty() ? "Impossible" : s) << endl;
  }

  return 0;
}

#include <bits/stdc++.h>



using ll = long long;
using ld = long double;

#define mp make_pair
#define pb push_back

#define filename "boysgirls"

using namespace std;

void die(void)
{
  exit(0);
}

void solve_odd(int n, int x, int y)
{
  if(x + y < n)
  {
    cout << "Impossible";
    die();
  }
  if(x + y == n)
  {
    if(x > 0 && y > 0)
    {
      cout << "Impossible";
      die();
    }
    if(x == 0)
    {
      for(int i = 0; i < n; i++)
        cout << "B";
      die();
    }
    if(y == 0)
    {
      for(int i = 0; i < n; i++)
        cout << "G";
      die();
    }
  }
  if((x + y - n) % 2 != 0)
  {
    cout << "Impossible";
    die();
  }
  int  k = (x + y - n)/2;
  vector<int> a;
  a.pb(x - 2 * k + 1);
  a.pb(y - 2 * k + 1);
  for(int i = 0; i < 2 * k - 2; i++)
    a.pb(1);
  vector<char> res;
  for(int i = 0; i < 2 * k; i++)
    for(int j = 0; j < a[i]; j++)
      if(i % 2 == 0)
        res.pb('B');
      else
        res.pb('G');
  int q = 0;
  vector<char> ans;
  ans.resize(n);
  for(int i = 0; i < n; i++)
  {
    ans[q] = res[i];
    q = (q + 2) % n;
  }
  for(int i = 0; i < n; i++)
    cout << ans[i];
  die();
}
solve_even(int n, int x, int y)
{
  if((x + y - 2*n)%2 != 0)
  {
    cout << "Impossible";
    die();
  }
  int sm = (x + y - 2*n)/2;//s + m
  int r = (2*n + x - y)/2;//a + b
  for(int s = 1; s < sm; s++)
  {
    int m = sm - s;
    int minb = m;
    int maxb = (n - m);
    int mina = s;
    int maxa = (n - s);
    if(minb <= maxb && mina <= maxa && (mina + minb) <= r && (maxa + maxb) >= r)
    {
      int a = mina, b = minb;
      if(maxa + b < r)
        a = maxa;
      else
        a = (r - b);
      b = (r - a);
      int a1 = a - s + 1;
      int a2 = (n - a) - s + 1;
      int b1 = b - m + 1;
      int b2 = (n - b) - m + 1;
      vector<char> aa;
      vector<char> bb;
      for(int i = 0; i < a1; i++)
        aa.pb('B');
      for(int i = 0; i < a2; i++)
        aa.pb('G');
      for(int i = 0; i < s - 1; i++)
      {
        aa.pb('B');
        aa.pb('G');
      }
      for(int i = 0; i < b1; i++)
        bb.pb('B');
      for(int i = 0; i < b2; i++)
        bb.pb('G');
      for(int i = 0; i < m - 1; i++)
      {
        bb.pb('B');
        bb.pb('G');
      }
      for(int i = 0; i < n; i++)
      {
        cout << aa[i] << bb[i];
      }
      die();
    }
  }
  if(x == 2 * n && y == 0)
  {
    for(int i = 0; i < 2 * n; i++)
      cout << 'B';
    die();
  }
  if(y == 2 * n && x == 0)
  {
    for(int i = 0; i < 2 * n; i++)
      cout << 'G';
    die();
  }
  if(x == n && y == n)
  {
    for(int i = 0; i < n; i++)
      cout << "BG";
    die();
  }
  x-=n;
  if(x + y <= n)
  {
    cout << "Impossible";
    die();
  }
  if(x > 0 && y <= n)
  {
  	int k = (x + y - n)/2;
  	vector<int> a;
    a.pb(x - 2 * k + 1);
    a.pb(y - 2 * k + 1);
    for(int i = 0; i < 2 * k - 2; i++)
      a.pb(1);
    vector<char> res;
    for(int i = 0; i < 2 * k; i++)
      for(int j = 0; j < a[i]; j++)
        if(i % 2 == 0)
          res.pb('B');
        else
          res.pb('G');
    for(int i = 0; i < n; i++)
      cout << 'B' << res[i];
    die();
  }
  x+=n;
  y-=n;
  if(y > 0 && x <= n)
  {
    int k = (x + y - n)/2;
  	vector<int> a;
    a.pb(x - 2 * k + 1);
    a.pb(y - 2 * k + 1);
    for(int i = 0; i < 2 * k - 2; i++)
      a.pb(1);
    vector<char> res;
    for(int i = 0; i < 2 * k; i++)
      for(int j = 0; j < a[i]; j++)
        if(i % 2 == 0)
          res.pb('B');
        else
          res.pb('G');
    for(int i = 0; i < n; i++)
      cout << 'G' << res[i];
    die();
  }
  cout << "Impossible";
  die();
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
	int n, x, y;
	cin >> n >> x >> y;
	if(n % 2 == 1)
	  solve_odd(n, x, y);
	if(n % 2 == 0)
	  solve_even(n/2, x, y);
	return 0;
}
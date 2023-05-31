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
                   
#define FILE_NAME "java2016"

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
  if  (scanf("%d", &n) < 1) {
    return 0;
  }
  return 1;
}

void solve() {
  if (n == 0)
  {
     cout << "a = ?/?" << endl;
     cout << "(a min a) min a" << endl;
     return;
  }
  char s = 'z'-13-1;
  vector<string> sol;
  string tmp = "";
  tmp.pb(s);
  sol.pb(tmp + "= ? max ?");
  s++;
  for (int i = 0; i < 9; i++)
  {  
     string op = ""; op.pb(s-1);
     string op2 = ""; op2.pb(s);
     sol.pb(op2 + "=(" + op + " max " + op + ") max " + op);
     s++;
   //  cerr << sol.back() << endl;
  }
  tmp = "";
  string tmp2 = "";
  tmp.pb(s-1);
  tmp2.pb(s);
  sol.pb(tmp2+" = ("+tmp+" max "+tmp+") / "+tmp);
  s++;
  for (int i = 0; s <= 'z'; i++)
  {
     string op = ""; op.pb(s-1);
     string op2 = ""; op2.pb(s);
     sol.pb(op2 + "=(" + op + " max " + op + ") max " + op);
     s++;
  }
  char one = 'z';
  tmp = ""; tmp.pb(one);
  sol.pb("a=" + tmp);
  for (char i = 'a'+1; i < 'h'; i++)
  {
     string op = ""; op.pb(char(i-1));
     string op2 = ""; op2.pb(char(i));
     sol.pb(op2 + "=" + op + "+" + op);
   //  cerr << sol.bac
  }

  string last = "";
  for (int i = 0; i < 8; i++)
     if (n & (1<<i)) 
     {
        if (last != "") last.pb('+');
        last.pb(char(i+'a'));
     }
  for (int i = 0; i < (int)sol.size(); i++) cout << sol[i] << endl;
  int res = 0;
  for (int i = 0; i < (int)sol.size(); i++)
     for (int j = 0; j < (int)sol[i].size(); j++)
        if (sol[i][j] != ' ') res++;
  res+=last.size();
  cerr << res << endl;
  cout << last << endl;  
}

int main() {
  freopen(FILE_NAME ".in", "r", stdin);
  freopen(FILE_NAME ".out", "w", stdout);

  while (read()) {
    solve();
  }

  return 0;
}

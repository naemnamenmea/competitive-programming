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
  char s = 'k';
  vector<string> sol;
  string tmp = "";
  sol.pb("i=? max ?");
  sol.pb("j=i max i max i");
  for (int i = 0; i < 8; i++)
  {  
     string op = ""; op.pb(s-1);
     string op2 = ""; op2.pb(s);
     sol.pb(op2 + "=" + op + " max " + op + " max " + op);
     s++;
   //  cerr << sol.back() << endl;
  }
  tmp = "";
  tmp.pb(s);
  string tmp2 = ""; tmp2.pb(s-1);
  sol.pb(tmp+" = ("+tmp2+" max "+tmp2+") / "+tmp2);
  s++;
  for (int i = 0; i < 7; i++)
  {
     string op = ""; op.pb(s-1);
     string op2 = ""; op2.pb(s);
     sol.pb(op2 + "=" + op + " max " + op);
     s++;
  }
  char one = 'z';
  tmp = ""; tmp.pb(one);
  sol.pb("a=" + tmp);
  for (char i = 'a'+1; i < 'c'; i++)
  {
     string op = ""; op.pb(char(i-1));
     string op2 = ""; op2.pb(char(i));
     sol.pb(op2 + "=" + op + "+" + op);
   //  cerr << sol.bac
  }
  for (char i = 'c'; i <= 'h'; i++)
  {
     string op = ""; op.pb(char(i-1));
     string op2 = ""; op2.pb(char(i));
     sol.pb(op2 + "=" + op + "*b");
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
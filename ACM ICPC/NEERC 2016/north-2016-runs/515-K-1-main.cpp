#include "bits/stdc++.h"

using namespace std;

int main()
{
  freopen("king.in","r",stdin);
  freopen("king.out","w",stdout);
  vector<vector<int>>  v;
  int n, dd, md, yd, d,m,y;
  cin >> dd >> md >> yd;
  cin >> n;
  bool b = false;
  for (int i = 1; i <= n; i++)
  {
    cin >> d >> m >> y;
    if (d == dd && m == md && (yd - y) == 18)
    {
      cout << i;
      return 0;
    }
    if (yd - y >= 18)
    {
      vector<int> v1;
      v1.push_back(y);
      v1.push_back(m);
      v1.push_back(d);
      v1.push_back(i);
      v.push_back(v1);
      b = true;
    }
  }
  if (!b)
  {
    cout << -1;
    return 0;
  }
  sort(v.begin(),v.end(), [](vector<int> &v1, vector<int> &v2){ return (v1[0] < v2[0] || (v1[0]  == v2[0] && v1[1] < v2[1]) ||(v1[0]  == v2[0] && v1[1] == v2[1] && v1[2] < v2[2]));});
  for (int i = v.size()-1; i >=0; i--)
    if(yd - v[i][0] > 18 ||(yd - v[i][0] == 18 && v[i][1] < md)||(yd - v[i][0] == 18 && v[i][1] == md && v[i][2] <= dd))
    {
      cout << v[i][3];
      return 0;
    }
}

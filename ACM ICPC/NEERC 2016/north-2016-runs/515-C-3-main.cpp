#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> g;
int sum = 0;
void dfs(int v, vector<bool> &used)
{
  used[v] = true;
  sum++;
  for (auto i: g[v])
    if (!used[i])
      dfs(i,used);
}
int main()
{
  freopen("codecoder.in","r",stdin);
  freopen("codecoder.out","w",stdout);
  vector<pair<int,int>> v;
  int n,x,y;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    vector<int> v1;
    for (int j = i-1; j >= 0; j--)
      {
        if (x > v[j].first || y > v[j].second)
          v1.push_back(j);
        if (x < v[j].first || y < v[j].second)
          g[j].push_back(i);
      }
    g.push_back(v1);
    v.push_back(make_pair(x,y));
  }

  for (int i = 0; i < n; i++)
  {
    vector<bool> used(n);
    sum = 0;
    dfs(i,used);
    cout << sum-1 << '\n';
  }
  return 0;
}



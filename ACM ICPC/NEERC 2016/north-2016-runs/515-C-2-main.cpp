/*#include "bits/stdc++.h"

using namespace std;

int main()
{
  //freopen("folding.in","r",stdin);
  //freopen("folding.out","w",stdout);
  int H,h,W,w;
  int i = 0;
  cin >> W >> H >> w >> h;

  if (H > W)
  {
     if ( h < w) swap(h,w);
  }
  else
     if ( h > w) swap(h,w);
     if(( h > H)||(w > W))
     {
       cout << -1;
       return 0;
     }


  while (H != h && W != w)
  {


    if (( H == w)&&(W != w))
  {
    swap(w,h);
  }
  if ((W == h)&&(H != h))
  {
    swap(w,h);
  }

    if (H!=h)
    {
      if ((( H/2 >= h)&&(H % 2 == 0))||((H/2+1 >= h)&&(H % 2 != 0)))
    {
      if ( H % 2 != 0 ) H++;
      H/=2;
      i++;
    }
    else
    {
      H = H - (H-h);
      i++;
    }
    }

      if (( H == w)&&(W != w))
  {
    swap(w,h);
  }
  if ((W == h)&&(H != h))
  {
    swap(w,h);
  }

    if (W != w)
      {
        if ((( W/2 >= w)&&(W % 2 == 0))||((W/2+1 >= w)&&(W % 2 != 0)))
    {
      if ( W % 2 != 0 ) W++;
      W/=2;
      i++;
    }
    else
    {
       W = W - (W-w);
       i++;
    }
    }
    }
    cout << i;
    return 0;
}*/










#include "bits/stdc++.h"
using namespace std;

vector<vector<long long>> g;
long long sum = 0;
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
  vector<pair<long long,long long>> v;
  long long n,x,y;
  cin >> n;
  for (long long i = 0; i < n; i++)
  {
    cin >> x >> y;
    vector<long long> v1;
    for (long long j = i-1; j >= 0; j--)
      {
        if (x > v[j].first || y > v[j].second)
          v1.push_back(j);
        if (x < v[j].first || y < v[j].second)
          g[j].push_back(i);
      }
    g.push_back(v1);
    v.push_back(make_pair(x,y));
  }

  for (long long i = 0; i < n; i++)
  {
    vector<bool> used(n);
    sum = 0;
    dfs(i,used);
    cout << sum-1 << '\n';
  }
  return 0;
}




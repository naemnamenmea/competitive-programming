#include "bits/stdc++.h"

using namespace std;

int main()
{
  freopen("folding.in","r",stdin);s
  freopen("folding.out","w",stdout);
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


  while (H != h)
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

      while (W != w)
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
    cout << i;
    return 0;
}


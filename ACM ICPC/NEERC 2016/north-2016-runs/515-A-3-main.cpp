/*#include "bits/stdc++.h"

using namespace std;

int main()
{
  //freopen("king.in","r",stdin);
 // freopen("king.out","w",stdout);
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
      H/=2;
      i++;
    }
    else
    {
      H-=h;
      i++;
    }

      while (W != w)
    if ((( W/2 >= w)&&(H % 2 == 0))||((W/2+1 >= w)&&(W % 2 != 0)))
    {
      W/=2;
      i++;
    }
    else
    {
       W-=w;
       i++;
    }
    cout << i;
    return 0;
}*/

#include <iostream>

using namespace std;

int main()
{
  freopen("anniversary.in","r",stdin);
  freopen("anniversary.out","w",stdout);
  long long w,h;
  cin >> w >>h;
  long long ax,ay,bx,by;
  cin >> ax>>ay>>bx>>by;
  long long ans1x, ans1y, ans2x, ans2y;
  if ((ax-bx != 0 && ay-by !=0) || (abs(ax-ay) > 1) || (abs(bx-by) > 1))
  {
    long long npx, npy;
    if (ay==by)
    {
      npx = (ax<bx) ? (ax+1): (bx + 1);
      npy = by;
    }
    else if (ax == bx)
    {
      npx = ax;
      npy = (ay<by) ? (ay+1) : (by+1);
    }
    else{
    npx = ax;
    npy = by;}
    if ((ax >= bx && ay >= by) || (ax <=bx && ay<=by)) {
    ans1x = (((npy + npx) - h) < 0) ? (0) : ((npy + npx) - h);
    ans1y = (((npy + npx) - h) < 0) ? (npy+npx) : (h);
    ans2x = ((npy + npx) > w) ? (w) : (npy+npx);
    ans2y = ((npy+npx) > w) ? (npy + npx - w) : (0);}
    else{
      ans1x = ((h - npy + npx > w)) ? (w) : (h - npy + npx);
      ans1y = ((h - npy + npx > w)) ? (w + npy - npx) : (h);
      ans2x = ((npx - npy) < 0) ? (0) : (npx-npy);
      ans2y = ((npx - npy) < 0) ? (npy-npx) : (0);
    }
  }
  else{
    if (ax == bx)
    {
      ans1x = 0;
      ans1y = (ay< by) ? (ay) : (by);
      ans2x = w;
      ans2y = ans1y+1;
    }
    else{
      ans1x = (ax<bx) ? (ax) : (bx);
      ans1y = h;
      ans2x = ans1x+1;
      ans2y = 0;
    }
  }

  cout << ans1x << " " << ans1y << " " << ans2x << " " << ans2y << " ";
  return 0;
}

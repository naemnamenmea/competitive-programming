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
      ans1x = ((h - npx + npy > w)) ? (w) : (h - npx + npy);
      ans1y = ((h - npx + npy > w)) ? (w + npx - npy) : (h);
      ans2x = ((npx - npy) < 0) ? (npy - npx) : (0);
      ans2y = ((npx - npy) < 0) ? (0) : (npx-npy);
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

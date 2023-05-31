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
    npx = ax;
    npy = by;
    ans1x = (((npy + npx) - h) < 0) ? (0) : ((npy + npx) - h);
    ans1y = (((npy + npx) - h) < 0) ? (npy+npx) : (h);
    ans2x = ((npy + npx) > w) ? (w) : (npy+npx);
    ans2y = ((npy+npx) > w) ? (npy + npx - w) : (0);
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
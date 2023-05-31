#include <iostream>
#include <stdio.h>

using namespace std;

int main (void)
{
  freopen("anniversary.in","r",stdin);
  freopen("anniversary.out","w",stdout);

  long int w,h,x1,y1,x2,y2;

  int i;
  cin>>w>>h>>x1>>y1>>x2>>y2;

  int swaps;

  if (y1<y2)
  {
    swaps=y2;
    y2=y1;
    y1=swaps;

    swaps=x2;
    x2=x1;
    x1=swaps;
  }

  if(x1<=x2)
  {
    x1++;
    x2--;
    y1=h;
    y2=0;
  }
  else
  {
    if(y1!=y2)
    {
      x1--;
      x2++;
      y1=h;
      y2=0;
    }
    else
    {
      y1++;
      y2--;
      x1=w;
      x2=0;
    }
  }



  cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2;

  fclose(stdin);
  fclose(stdout);

  return 0;
}

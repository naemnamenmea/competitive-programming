#include <iostream>
#include <stdio.h>

using namespace std;

int main (void)
{
  int num = 0, Sc;
  int dd, dm, dy;
  int cd = 0, cm = 0, cy = 0;
  long long int c, d, b;
  freopen("king.in","r",stdin);
  freopen("king.out","w",stdout);

  cin >> dd >> dm >> dy;
  cin >> Sc;
  d = dy * 10000 + dm * 100 + dd;
  b = 0;
  for(int i = 1; i <= Sc; i ++)
  {
      cin >> cd >> cm >> cy;
      c = cy * 10000 + cm * 100 + cd;
      if (d - c >= 180000) {
        if (c > b) {
          num = i;
          b = c;
          }
        }
  }

  if(num == 0)
        cout << -1;
  else
        cout << num;


  fclose(stdin);
  fclose(stdout);

  return 0;
}


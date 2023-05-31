#include <iostream>
#include <algorithm>
using namespace std;

int log(int a, int b)
{
   int c = 0;
   while (a > b)
   {
       c++;
       a = a/2;
   }
   return(c);
}
int main()
{
      freopen("folding.in", "r", stdin);
      freopen("folding.out", "w", stdout);
      int a,b,c,d;
      int s1,s2;
      s1 = -1;
      s2 = -1;
      cin >> a >> b >> c >> d;
      if ((a>=c) && (b >=d))
      {
          s1 = log(a,c)+ log(b,d);
      }
      if ((a>=d) && (b >=c))
      {
          s2 = log(a,d)+ log (b,c);
      }
      if ((s1 == -1) && (s2 == -1))
        cout << -1;
      else
      {
          if (s1 == -1)
            cout << s2;
          else
          {
              if (s2 == -1)
                cout << s1;
              else
                cout << min(s1,s2);
          }
      }

}

#include<iostream>
using namespace std;
int main()
{
    freopen("anniversary.in" , "r" , stdin);
    freopen("anniversary.out" , "w" , stdout);
    int h , w , x1 , y1 , x2 , y2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2 ;
    if( x1 != x2)
    {
        cout << x1 << " " << 0 << " " <<  x2 << " " << h;
    }
     else
      {
        cout << 0 << " " << y1 << " " <<  w << " " << y2;
      }
 return 0;
}

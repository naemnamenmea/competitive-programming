#include<iostream>
using namespace std;
int main()
{
    freopen("anniversary.in" , "r" , stdin);
     freopen("anniversary.out" , "w" , stdout);
    int h , w , x1 , y1 , x2 , y2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2 ;
    int ex = 0 , ey = 0;
    for(int i = x1; i <= w ; i++)
    {
     if( (h * x1 - i * y1 ) * (h * x2 - i * y2 ) < 0)
     {
         cout << 0 << " " << 0 << " " << i << " " << h;
     }
    }


}

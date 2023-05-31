#include <iostream>

using namespace std;

int main()
{
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);
    int w,h,ax,ay,bx,by;
    int x1,y1,x2,y2;
    cin >> w >> h >> ax >> ay >> bx >>by;
    if (ax!= bx)
    {
        y1 = 0;
        y2 = h;
        x1 = ax;
        x2 = bx;
    }
    else
    {
        x1 = 0;
        x2 = w;
        y1 = ay;
        y2 =by;


    }
    cout << x1 << " "<< y1 << " "<< x2 << " "<< y2;
}

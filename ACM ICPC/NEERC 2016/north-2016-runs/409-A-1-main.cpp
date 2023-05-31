#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("anniversary.in","r",stdin);
    freopen("anniversary.out","w",stdout);
    long ax, ay, w, h, bx, by;
    cin >> w >> h >> ax >> ay >> bx >> by;
    if (ax==bx){
    cout << 0 <<" "<< ay<<" "<< w<<" "<< by;
    }
    else {
        cout << ax <<" "<< 0<<" "<< bx<<" "<< h;
    }
    return 0;
}

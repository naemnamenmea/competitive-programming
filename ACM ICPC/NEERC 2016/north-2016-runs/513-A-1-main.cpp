#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("anniversary.in");
    ofstream cout("anniversary.out");
    long long w, h, ax,ay,bx,by;
    cin >> w >>h >> ax >> ay >> bx >> by;
    if (ax == bx)
    {
        cout << 0 <<  " " << ay << " " << w << " " << by;
         return 0;
    }
    if (ay== by)
    {
        cout << ax <<  " " << 0 << " " << bx << " " << h;
         return 0;
    }
    cout << ax <<  " " << 0 << " " << bx << " " << h;
    return 0;
}


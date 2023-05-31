#include <bits/stdc++.h>

using namespace std;

#define taskname "anniversary"
#define taski taskname".in"
#define tasko taskname".out"

#define inp freopen(taski, "r", stdin)
#define outp freopen(tasko, "w", stdout)

int w,h,ax,ay,bx,by;

int main()
{
    inp; outp;
    ios_base::sync_with_stdio(false);
    cin >> w >> h;
    cin >> ax >> ay >> bx >> by;
    if(ax==bx)
    {
        cout << 0 << " " << min(ay,by) << " " << w << " " << max(ay,by);
        return 0;
    }
    cout << min(ax,bx) << " " << 0 << " " << max(ax,bx) << " " << h;
    return 0;
}

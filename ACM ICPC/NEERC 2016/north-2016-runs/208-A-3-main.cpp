#include <bits/stdc++.h>

using namespace std;

int w, h, x1, y, x2, y2;

int main()
{
//##################################
#ifndef DEBUG
    #define prob "anniversary"
    freopen(prob ".in",  "r", stdin);
    freopen(prob ".out",  "w", stdout);
#endif
//##################################
//##################################
#ifdef DEBUG
    freopen("../input.txt",  "r", stdin);
    freopen("../output.txt",  "w", stdout);
    //freopen("../debug.txt",  "w", stderr);
#endif
//##################################
    cin >> w >> h >> x1 >> y >> x2 >> y2;
    if (x1 != x2)
        cout << min(x1, x2) << " " << 0 << " " << max(x1, x2) << " " << h << endl;
    else
        cout << 0 << " " << min(y, y2) << " " << w << " " << max(y, y2) << endl;
    return 0;
}
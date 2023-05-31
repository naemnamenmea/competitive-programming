#include <bits/stdc++.h>

using namespace std;

long long w, h, W, H, ans, d, c1, c2, z1, z2;


int main()
{
//##################################
#ifndef DEBUG
    #define prob "folding"
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
    cin >> W >> H >> w >> h;
    if (H > W)
        swap(W, H);
    if (h > w)
        swap (w, h);

    if (h > H || w > W)
    {
        cout << -1 << endl;
        return 0;
    }

    d = 1;
    while ((double) W / d > w)
    {
        d *= 2;
        c1++;
    }
    d = 1;
    while ((double) H / d > h)
    {
        d *= 2;
        c2++;
    }
    d = 1;
    while ((double) W / d > h)
    {
        d *= 2;
        z1++;
    }
    d = 1;
    while ((double) H / d > w)
    {
        d *= 2;
        z2++;
    }
    cout << min(c1 + c2, z1 + z2) << endl;
    return 0;
}

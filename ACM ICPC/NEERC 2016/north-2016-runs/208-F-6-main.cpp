#include <bits/stdc++.h>

using namespace std;

long long w, h, W, H, ans, d;


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
    while (W / d > w)
    {
        d *= 2;
        ans++;
    }
    d = 1;
    while (H / d > h)
    {
        d *= 2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}

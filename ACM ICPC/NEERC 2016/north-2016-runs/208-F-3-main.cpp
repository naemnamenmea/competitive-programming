#include <bits/stdc++.h>

using namespace std;

double w, h, W, H;
int c1, c2;
double d1, d2;

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
    if (max(w, h) > max(W, H))
    {
        cout << -1 << endl;
        return 0;
    }
    d1 = max(W, H);
    d2 = min(W, H);
    while (d1 > max(w, h))
    {
        c1++;
        d1 /= 2;
    }
    while (d2 > min(w, h))
    {
        c2++;
        d2 /= 2;
    }
    cout << c1 + c2 << endl;
    return 0;
}

#include <iostream>

using namespace std;

int w, h, W, H, c1, c2;
int a[50];

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
    cin >> W >> h >> w >> h;
    a[0] = 1;
    for (int i = 1; i < 50; i++)
    {
        a[i] = a[i - 1]*2;
        if (a[i] > 10^9)
            break;
    }
    if (max(w, h) > max(W, H))
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i < 50; i++)
        if (c1 == 0 && (min(W, H) - min(w, h)) <= a[i])
            c1 = i;
    for (int i = 1; i < 50; i++)
        if (c2 == 0 && (max(W, H) - max(w, h)) <= a[i])
            c2 = i;
    cout << c1 + c2 << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;

typedef long long ll;

#define FNAME "anniversary" 

int main()
{
#ifdef FNAME
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    ll w, h, ax, ay, bx, by;
    cin >> w >> h >> ax >> ay >> bx >> by;

    bool swapped = false;
    if (ax == bx) {
        swap(w, h);
        swap(ax, ay), swap(bx, by);
        swapped = true;
    }

    //if (ax > bx) swap(ax, bx), swap(ay, by);
    int ansax = ax, ansay = 0;
    int ansbx = bx, ansby = h;

    if (swapped) swap(ansax, ansay), swap(ansbx, ansby);
    cout << ansax << " " << ansay << " " << ansbx << " " << ansby;

    return 0; 
}
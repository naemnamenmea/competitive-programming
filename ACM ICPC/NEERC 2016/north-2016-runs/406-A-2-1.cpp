#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("anniversary.in", "r", stdin);
    freopen ("anniversary.out", "w", stdout);
    long long w, h, ax, ay, bx, by;
    cin >> w >> h >> ax >> ay >> bx >> by;
    if (ax != bx)
        cout << ax << ' ' << 0 << ' ' << bx << ' ' << h;
    else
        cout << 0 << ' ' << ay << ' ' << w << ' ' << by;
    return 0;
}

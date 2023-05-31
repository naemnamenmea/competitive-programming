#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);
    int w, h, ax, ay, bx, by;
    cin >> w >> h;
    cin >> ax >> ay;
    cin >> bx >> by;
    if (ax != bx) {
        if (ax > bx)
            swap(ax, bx);
        cout << ax << " 0 " << bx << " " << h << "\n";
    } else {
        if (ay > by)
            swap(ay, by);
        cout << "0 " << ay << ' ' << w << " " << by;
    }
    return 0;
}

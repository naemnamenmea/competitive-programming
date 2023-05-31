#define FNAME "anniversary"

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (n); i++)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin() v.end()

using namespace std;

int main() {
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);

    int w, h, ax, ay, bx, by;
    cin >> w >> h >> ax >> ay >> bx >> by;
    if (ax != bx) {
        cout << min(ax, bx) << " " << 0 << " " << max(ax, bx) << " " << h << endl;
    } else
        cout << 0 << " " << min(ay, by) << " " << w << " " << max(ay, by) << endl;
    return 0;
}
#define FNAME "folding"

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

int get_num(int a, int b) {
    if (a < b) {
        return 1000;
    }
    int ans = 0;
    while (a != b)   {
        int c = a / 2;
        if (a & 1)
            ++c;
        if (c > b) {
            ++ans;
            a = c;
            continue;
        }
        a = b;
        ++ans;
        break;  
    }
    return ans;
}

int main() {
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
    int q, w, e, r;
    cin >> q >> w >> e >> r;
    int ans = min(get_num(q, e) + get_num(w, r), get_num(q, r) + get_num(w, e));
    if (ans >= 1000)
        ans = -1;
    cout << ans;
    return 0;
}
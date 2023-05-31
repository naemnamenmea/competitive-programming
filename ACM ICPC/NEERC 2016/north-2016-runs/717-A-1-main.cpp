#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define push_back pb

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "anniversary"
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);

    int w,h,ax,ay,bx,by;
    cin >> w >> h >> ax >> ay >> bx >> by;
    if(ax != bx) {
        cout << ax << ' ' << 0 << ' ' << bx << ' ' << h << '\n';
    }
    else {
        cout << 0 << ' ' << ay << ' ' << w << ' ' << by << '\n';
    }

    return 0;
}
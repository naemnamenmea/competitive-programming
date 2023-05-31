#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("anniversary.in", "r", stdin); freopen("anniversary.out", "w", stdout);
    int w, h;
    cin >> w >> h;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 != x2)
    	cout << x1 << ' ' << 0 << ' ' << x2 << ' ' << h << '\n';
    else
    	cout << 0 << ' ' << y1 << ' ' << w << ' ' << y2 << '\n';
    return 0;
}

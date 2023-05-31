#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);

    int w, h;
    cin >> w >> h;

    int x1, y1, x2, y2;

    pair<int, int> a, b;
    cin >> x1 >> y1 >> x2 >> y2;

    a = {x1, y1};
    b = {x2, y2};
    if (a > b)
        swap(a, b);

    if (a.first != b.first) {
        if (a.first + 1 != b.first) {
            cout << a.first + 1 << " 0" << endl << a.first + 1 << " " << h;
        } else {
            cout << a.first << " 0" << endl << a.first + 1 << " " << h;
        }
    } else {
        if (a.second + 1 != b.second) {
            cout << "0 " << a.second + 1 << endl << w << " " << a.second + 1;
        } else {
            cout << "0 " << a.second << endl << w << " " << a.second + 1;
        }
    }

    return 0;
}
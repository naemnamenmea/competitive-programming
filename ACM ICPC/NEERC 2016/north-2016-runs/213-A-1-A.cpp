#include <bits/stdc++.h>

using namespace std;

#define FILE "anniversary"

int main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);

    int max_x, max_y;
    int x_1, y_1, x_2, y_2;

    cin >> max_x >> max_y >> x_1 >> y_1 >> x_2 >> y_2;

    if (x_1 != x_2) {
        cout << x_1 << " " << 0 << " " << x_2 << " " << max_y << endl;
    } else {
        cout << 0 << " " << y_1 << " " << max_x << " " << y_2 << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define FILE "king"

struct Date {
    int d, m, y;
};

int n;
Date p[1000];

int main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);

    cin >> p[0].d >> p[0].m >> p[0].y;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> p[i].d >> p[i].m >> p[i].y;
    }

    int ind = -1;
    for (int i = 1; i <= n; ++i) {
        int yy = p[0].y - p[i].y;

        if (yy > 18 || (yy == 18 && (p[i].m < p[0].m || (p[i].m == p[0].m && p[i].d <= p[0].d)))) {
            if (ind == -1
                || (p[i].y > p[ind].y
                    || (p[i].y == p[ind].y && p[i].m > p[ind].m)
                    || (p[i].y == p[ind].y && p[i].m == p[ind].m && p[i].d > p[ind].d))) {
                ind = i;
            }
        }
    }
    cout << ind << endl;
    return 0;
}

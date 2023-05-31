#include <bits/stdc++.h>
using namespace std;

struct gay {
    int d, m, y, num;
};

bool cmp(gay a, gay b) {
    if (a.y > b.y) return 1;
    if (a.y < b.y) return 0;
    if (a.m > b.m) return 1;
    if (a.m < b.m) return 0;
    if (a.d > b.d) return 1;
    if (a.d < b.d) return 0;
}

int main() {
    freopen ("king.in", "r", stdin);
    freopen ("king.out", "w", stdout);
    int kd, km, ky, n;
    cin >> kd >> km >> ky >> n;
    gay son[n];
    for (int i = 0; i < n; i++) {
        cin >> son[i].d >> son[i].m >> son[i].y;
        son[i].num = i;
    }
    sort(son, son + n, cmp);
    for (int i = 0; i < n; i++) {
        bool kek = 1;
        if (ky - son[i].y > 18)
            kek = 1;
        else if (ky - son[i].y < 18)
            kek = 0;
        else {
            if (km - son[i].m > 0)
                kek = 1;
            else if (km - son[i].m < 0)
                kek = 0;
            else {
                if (kd - son[i].d >= 0)
                    kek = 1;
                else if (kd - son[i].d < 0)
                    kek = 0;
            }
        }
        if (kek) {
            cout << son[i].num + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}

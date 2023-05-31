#include <bits/stdc++.h>

using namespace std;

#define FILE "codecoder"

struct T {
    int i, x, y;
};

int n;
vector <T> t;
vector <int> max_y, max_x;
vector <int> ans, p1, p2, a, b;

bool cmp1(int a, int b) {
    if (t[a].x != t[b].x) {
        return t[a].x < t[b].x;
    }

    if (t[a].y != t[b].y) {
        return t[a].y < t[b].y;
    }

    return t[a].i < t[b].i;
}

bool cmp2(int a, int b) {
    if (t[a].y != t[b].y) {
        return t[a].y < t[b].y;
    }

    if (t[a].x != t[b].x) {
        return t[a].x < t[b].x;
    }

    return t[a].i < t[b].i;
}

int main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);

    cin >> n;
    t.resize(n);
    for (int i = 0; i < n; ++i) {
        t[i].i = i;
        cin >> t[i].x >> t[i].y;
    }

    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i] = b[i] = i;
    }

    sort(a.begin(), a.end(), cmp1);
    sort(b.begin(), b.end(), cmp2);

    p1.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        p1[a[i]] = i;
    }

    p2.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        p2[b[i]] = i;
    }

    ans.assign(n, 0);
    max_y.assign(n, 0);
    max_x.assign(n, 0);

    max_y[0] = a[0];
    for (int i = 1; i < n; ++i) {
        max_y[i] = max_y[i - 1];
        if (cmp2(max_y[i], a[i])) {
            max_y[i] = a[i];
        }
    }

    max_x[0] = b[0];
    for (int i = 1; i < n; ++i) {
        max_x[i] = max_x[i - 1];
        if (cmp1(max_x[i], b[i])) {
            max_x[i] = b[i];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        int imy = max_y[i];
        int imx = max_x[p2[imy]];
        int ians = p1[max_x[p1[imx]]];

        if (ians > i) {
            ans[i] = ans[ians];
        } else {
            ans[i] = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[p1[i]] << endl;
    }

    return 0;
}

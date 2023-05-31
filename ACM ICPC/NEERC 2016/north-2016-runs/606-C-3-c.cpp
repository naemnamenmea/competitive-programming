#include <bits/stdc++.h>

using namespace std;

int const N = 200200;
int const SZ = 1100100;

int tree[SZ];

void add(int pos, int val) {
    for (int x = pos + 1; x < SZ; x += x & -x) {
        tree[x] += val;
    }
}

int get(int bound) {
    int ret = 0;
    for (int i = bound; i > 0; i &= i - 1) {
        ret += tree[i];
    }
    return ret;
}

int main() {
    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);

    int n;
    scanf("%d", &n);
    
    static int x[N], y[N];
    
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", x + i, y + i);
    }
    
    static int indx[N];
    iota(indx, indx + n, 0);
    sort(indx, indx + n, [](int i, int j) {
        return x[i] < x[j];
    });
    
    static int indy[N];
    iota(indy, indy + n, 0);
    sort(indy, indy + n, [](int i, int j) {
        return y[i] < y[j];
    });
    
    static int maxx[N], maxy[N];
    copy(x, x + n, maxx);
    copy(y, y + n, maxy);
    
    static int ord[N];
    iota(ord, ord + n, 0);
    
    for (int it = 0; it < 20; ++it) {
    
        sort(ord, ord + n, [](int i, int j) {
            return maxx[i] < maxx[j];
        });

        int mx = -1;
        int my = -1;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            int p = ord[i];
            while (j < n && x[indx[j]] <= maxx[p]) {
                mx = max(mx, maxx[indx[j]]);
                my = max(my, maxy[indx[j]]);
                ++j;
            }
            maxx[p] = max(maxx[p], mx);
            maxy[p] = max(maxy[p], my);
        }

        sort(ord, ord + n, [](int i, int j) {
            return maxy[i] < maxy[j];
        });

        mx = -1;
        my = -1;
        j = 0;
        for (int i = 0; i < n; ++i) {
            int p = ord[i];
            while (j < n && y[indy[j]] <= maxy[p]) {
                mx = max(mx, maxx[indy[j]]);
                my = max(my, maxy[indy[j]]);
                ++j;
            }
            maxx[p] = max(maxx[p], mx);
            maxy[p] = max(maxy[p], my);
        }
    }
    
    static int ans[N];
    fill(ans, ans + n, n - 1);

    sort(ord, ord + n, [](int i, int j) {
        return maxx[i] < maxx[j];
    });    
    
    int j = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        int p = ord[i];
        while (j >= 0 && maxx[p] <= x[indx[j]]) {
            add(y[indx[j]], 1);
            --j;
        }
        ans[p] -= get(SZ - 1) - get(y[p] + 1);
    }
    
    for (int i = 0; i < n; ++i)
        cout << ans[i] << '\n';
}
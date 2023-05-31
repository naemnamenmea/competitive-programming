#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
int const N = 100100;

vector<int> g[N], rg[N];
bool used[N];
vector<int> order;

void topsort(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            topsort(to);
        }
    }
    order.push_back(v);
}

int color[N];

void coloring(int v, int c) {
    color[v] = c;
    for (int from : rg[v]) {
        if (color[from] < 0) {
            coloring(from, c);
        }
    }
}

int main() {
    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);

    int n;
    scanf("%d", &n);
    
    static int c[N], t[N];
    
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", c + i, t + i);
    }
    
    static int ind[N];
    iota(ind, ind + n, 0);
    sort(ind, ind + n, [](int i, int j) {
        return c[i] < c[j];
    });
    for (int i = 1; i < n; ++i) {
        g[ind[i]].push_back(ind[i - 1]);
        rg[ind[i - 1]].push_back(ind[i]);
    }
    
    sort(ind, ind + n, [](int i, int j) {
        return t[i] < t[j];
    });
    for (int i = 1; i < n; ++i) {
        g[ind[i]].push_back(ind[i - 1]);
        rg[ind[i - 1]].push_back(ind[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            topsort(i);
        }
    }
    
    reverse(order.begin(), order.end());
    fill(color, color + n, -1);
    int cnt = 0;
    for (int v : order) {
        if (color[v] < 0) {
            coloring(v, cnt);
            ++cnt;
        }
    }
    
    static set<int> cond[N];
    for (int i = 0; i < n; ++i) {
        for (int j : g[i]) {
            cond[color[i]].insert(color[j]);
        }
    }
    
    static vector<int> cc[N];
    for (int i = 0; i < cnt; ++i) {
        cc[i] = vector<int>(cond[i].begin(), cond[i].end());
    }
    
    static int const SZ = 70700;
    static int popc[SZ];
    for (int i = 1; i < SZ; ++i) {
        popc[i] = popc[i >> 1] + (i & 1);
    }
    
    static int sz[N];

    for (int st = 0; st < n; st += 32) {
        static uint mask[N];
        fill(mask, mask + cnt, 0);
        int en = min(n, st + 32);
        for (int x = st; x < en; ++x) {
            mask[color[x]] |= 1 << (x - st);
        }
        for (int i = cnt - 1; i >= 0; --i) {
            for (int j : cc[i]) {
                mask[i] |= mask[j];
            }
            sz[i] += popc[mask[i] >> 16] + popc[mask[i] & ((1 << 16) - 1)];
        }
    }
    
    for (int i = 0; i < n; ++i)
        cout << sz[color[i]] - 1 << '\n';
}
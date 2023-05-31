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
    
    static int fr[N + N], to[N + N], start[N];
    int es = 0;
    for (int i = cnt - 1; i >= 0; --i) {
        start[i] = es;
        for (int j : cond[i]) {
            fr[es] = i;
            to[es++] = j;
        }
    }
    
    static int sz[N];

    for (int st = 0; st < n; st += 32) {
        static uint mask[N];
        fill(mask, mask + cnt, 0);
        int en = min(n, st + 32);
        int maxC = 0;
        for (int x = st; x < en; ++x) {
            mask[color[x]] |= 1 << (x - st);
            maxC = max(maxC, color[x]);
        }
        for (int x = start[maxC]; x < es; ++x) {
            mask[fr[x]] |= mask[to[x]];
        }
        for (int i = 0; i < cnt; ++i) {
            sz[i] += __builtin_popcount(mask[i]);
        }
    }
    
    for (int i = 0; i < n; ++i)
        cout << sz[color[i]] - 1 << '\n';
}
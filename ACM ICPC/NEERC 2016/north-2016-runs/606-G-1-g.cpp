#include <bits/stdc++.h>

using namespace std;

int const N = 100100;
int const LG = 19;
int const INF = 1e9 + 100;

vector<int> g[N];
int tin[N], tout[N];
vector<pair<int, int>> ch;
int up[LG][N];
int depth[N];
int sz[N];

void dfs(int v) {
    static int timer = 0;
    tin[v] = timer++;
    for (int i = 1; i < LG; ++i) {
        int x = up[i - 1][v];
        up[i][v] = up[i - 1][x];
    }
    sz[v] = g[v].empty() ? 1 : 0;
    for (int to : g[v]) {
        up[0][to] = v;
        depth[to] = depth[v] + 1;
        dfs(to);
        sz[v] += sz[to];
        if (v == 0) {
            ch.emplace_back(tout[to], to);
        }
    }
    tout[v] = timer;
}

int go_up(int a, int d) {
    if (d <= 0)
        return a;
    for (int i = 0; i < LG; ++i) {
        if (d & 1) {
            a = up[i][a];
        }
        d >>= 1;
    }
    return a;
}

int get_lca(int a, int b) {
    a = go_up(a, depth[a] - depth[b]);
    b = go_up(b, depth[b] - depth[a]);
    if (a == b)
        return a;
    for (int i = LG - 1; i >= 0; --i) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}

set<pair<int, int>> inch[N];

int calc(int c) {
    int left = inch[c].begin()->second;
    int right = inch[c].rbegin()->second;
    int lca = get_lca(left, right);
    cerr << "calc " << c << " : " << lca << ", " << sz[lca] << ' ' << inch[c].size() << endl;
    return sz[lca] - inch[c].size();
}

int main() {
    freopen("gangsters.in", "r", stdin);
    freopen("gangsters.out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    
    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d", &p);
        --p;
        g[p].push_back(i);
    }
    
    up[0][0] = 0;
    depth[0] = 0;
    dfs(0);
    
    int cnt = 0;
    int H = 0;
    
    for (int it = 0; it < q; ++it) {
        char tp;
        int v;
        scanf(" %c%d", &tp, &v);
        --v;
        int c = upper_bound(ch.begin(), ch.end(), make_pair(tin[v], INF)) - ch.begin();
        if (!inch[c].empty()) {
            --cnt;
            H -= calc(c);
        }
        if (tp == '+') {
            inch[c].insert({tin[v], v});
        } else {
            inch[c].erase({tin[v], v});
        }
        if (!inch[c].empty()) {
            ++cnt;
            H += calc(c);
        }
        cout << cnt << ' ' << H << '\n';
    }
}
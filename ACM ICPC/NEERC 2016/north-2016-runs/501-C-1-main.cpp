#include <bits/stdc++.h>

using namespace std;

#define TASK "codecoder"

const int MAXN = 1 << 17;

int n;
pair<int, int> a[MAXN];
pair<int, int> b[MAXN];
vector<int> e[MAXN];
vector<int> g[MAXN];
char vis[MAXN];
vector<int> vct;
int c[MAXN];
int cc;
int dp[MAXN];
int cnt[MAXN];
vector<int> vv[MAXN];

void dfs1(int v) {
    vis[v] = 1;
    for (int to : e[v]) {
        if (!vis[to]) {
            dfs1(to);
        }
    }
    vct.push_back(v);
}

void dfs2(int v) {
    c[v] = cc;
    cnt[cc]++;
    vv[cc].push_back(v);
    vis[v] = 1;
    for (int to : g[v]) {
        if (vis[to]) continue;
        dfs2(to);
    }
}

int main() {
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
        scanf("%d", &b[i].first);
        b[i].second = i;
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 1; i < n; i++) {
        e[a[i].second].push_back(a[i - 1].second);
        g[a[i - 1].second].push_back(a[i].second);

        e[b[i].second].push_back(b[i - 1].second);
        g[b[i - 1].second].push_back(b[i].second);
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs1(i);
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        int v = vct[n - i - 1];
        if (vis[v]) continue;
        dfs2(v);
        cc++;
    }

    for (int i = 0; i < n; i++) for (int to : e[i]) assert(c[to] >= c[i]);

    for (int i = cc - 1; i >= 0; i--) {
        vector<int> cv;
        for (int v : vv[i]) {
            for (int to : e[v]) {
                if (c[to] != c[v]) cv.push_back(c[to]);
            }
        }
        sort(cv.begin(), cv.end());
        cv.resize(unique(cv.begin(), cv.end()) - cv.begin());
        for (int x : cv) cnt[i] += cnt[x];
    }
    for (int i = 0; i < n; i++) printf("%d\n", cnt[c[i]] - 1);

    return 0;
}
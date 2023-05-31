#include <bits/stdc++.h>

using namespace std;

#define TASK "gangsters"

const int MAXK = 17;
const int MAXN = 1 << MAXK;

int n, q;
vector<int> e[MAXN];
int p[MAXN][MAXK];
int h[MAXN];
int cEdge;
int tp[MAXN];
int cnt[MAXN];
int L[MAXN], R[MAXN], tmr;

void dfs(int v, int pr, int ch) {
    p[v][0] = pr;
    for (int i = 1; i < MAXK; i++) p[v][i] = p[p[v][i - 1]][i - 1];
    h[v] = ch;
    tp[v] = cEdge;
    cnt[v] = e[v].empty();

    L[v] = tmr++;
    for (int i = 0; i < (int)e[v].size(); i++) {
        if (v == 0) cEdge = i;
        int to = e[v][i];
        dfs(to, v, ch + 1);
        cnt[v] += cnt[to];
    }
    R[v] = tmr++;
}

vector<set<pair<int, int> > > st1, st2;

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i = 0; i < MAXK; i++) if ((h[u] - h[v]) & (1 << i)) u = p[u][i];

    if (u == v) return u;
    for (int i = MAXK - 1; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

int count(int vert) {
    int t = tp[vert];
    if (st1[t].empty()) return 0;
    int u = st1[t].begin()->second;
    int v = st2[t].rbegin()->second;
    int w = lca(u, v);
    return cnt[w];
}

int main() {
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);

    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        --x;
        e[x].push_back(i);
    }
    scanf("\n");

    dfs(0, 0, 0);
    st1.resize(e[0].size());
    st2.resize(e[0].size());

    int cur = 0;
    int cc = 0;
    int c2 = 0;
    for (int i = 0; i < q; i++) {
        char c;
        int x;
        scanf("%c %d\n", &c, &x);
        x--;

        if (c == '+') {
            c2++;
            int t = tp[x];
            cc -= !st1[t].empty();
            cur -= count(x);
            st1[t].insert(make_pair(L[x], x));
            st2[t].insert(make_pair(R[x], x));
            cur += count(x);
            cc += !st1[t].empty();
        }
        if (c == '-') {
            c2--;
            int t = tp[x];
            cc -= !st1[t].empty();
            cur -= count(x);
            st1[t].erase(make_pair(L[x], x));
            st2[t].erase(make_pair(R[x], x));
            cur += count(x);            
            cc += !st1[t].empty();
        }
        //cerr << c << " " << x << " " << cc << " " << cur << endl;
        printf("%d %d\n", cc, cur - c2);
    }

    return 0;
}
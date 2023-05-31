#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define mkp make_pair
const int maxn = (int)1e5 + 1000;
vector<int> g[maxn], gr[maxn];
pii a[maxn], b[maxn];
int order[maxn];
int sz = 0;
bool used[maxn];
int comp[maxn];
vector<int> comp_g[maxn];
int ans[maxn];
int sizeComp[maxn];

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < (int)g[v].size(); ++i)
        if (!used[g[v][i]])
            dfs(g[v][i]);
    order[sz++] = v;
}

void dfs2(int v, int c) {
    used[v] = 1;
    comp[v] = c;
    for (int i = 0; i < (int)gr[v].size(); ++i)
        if (!used[gr[v][i]])
            dfs2(gr[v][i], c);
}

set<int> used_comps;
int cur_sum;

int comp_dfs(int c) {
    used[c] = 1;
    ans[c] = sizeComp[c];
    int r = 0;
    for (int i = 0; i < (int)comp_g[c].size(); ++i) {
        int c2 = comp_g[c][i];
        int cur_r = 0;
        if (!used[c2]) cur_r = comp_dfs(c2);
        else r += ans[c2];
        ans[c] -= cur_r;
        ans[c] += ans[comp_g[c][i]];
    }
    return r;
}

int main() {
    freopen("codecoder.in","r",stdin);
    freopen("codecoder.out","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &a[i].F, &b[i].F), a[i].S = b[i].S = i;
    sort(a, a + n), sort(b, b + n);
    for (int i = n - 1; i > 0; --i) g[a[i].S].pb(a[i - 1].S), gr[a[i - 1].S].pb(a[i].S);
    for (int i = n - 1; i > 0; --i) g[b[i].S].pb(b[i - 1].S), gr[b[i - 1].S].pb(b[i].S);
    //cerr << "sort\n";
    for (int v = 0; v < n; ++v)
        if (!used[v])
            dfs(v);
    //cerr << "dfs 1\n";
    memset(used, 0, sizeof(used));
    int c = 0;
    for (int i = n - 1; i >= 0; --i) {
        int v = order[i];
        if (!used[v]) {
            dfs2(v, c), ++c;
        }
    }
    //cerr << "dfs 2\n";
    memset(used, 0, sizeof(used));
    set<int> roots;
    for (int v = 0; v < n; ++v) {
        roots.insert(v);
    }
    for (int v = 0; v < n; ++v) {
        ++sizeComp[comp[v]];
        for (int i = 0; i < (int)g[v].size(); ++i) {
            int c1 = comp[v], c2 = comp[g[v][i]];
            if (c1 != c2) {
                comp_g[c1].pb(c2);
                roots.erase(c2);
            }
        }
    }
    for (int v = 0; v < n; ++v) {
        sort(comp_g[v].begin(), comp_g[v].end());
        int m = unique(comp_g[v].begin(), comp_g[v].end()) - comp_g[v].begin();
        while (comp_g[v].size() > m) comp_g[v].pop_back();
    }
    //cerr << "roots & comp_g\n";
    int root = *roots.begin();
    //cerr << ">= 1 root Exist\n";
    comp_dfs(root);
    //cerr << "comp_dfs\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[comp[i]] - 1 << '\n';
    }
    /*cerr << endl;
    for (int v = 0; v < n; ++v) cerr << comp[v] << ' ';
    cerr << endl;
    for (int v = 0; v < n; ++v) {
        cerr << v << " : ";
        for (int i = 0; i < (int)comp_g[v].size(); ++i) {
            cerr << comp_g[v][i] << ' ';
        }
        cerr << endl;
    }*/
    return 0;
}

/*
4
2 3
3 2
1 1
4 5
*/



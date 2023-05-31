#include <bits/stdc++.h>

using namespace std;

#define filename "gangsters"

vector<int> edge[1600001];
vector<pair<int, int> > eul;
pair<int, int> mn[1600001];
int lf[1600001];
int sz[1600001];
int in[1600001];
int lc[1600001];
const int INF = 1e9;

void dfs(int u, int lv, int a){
    a = a==0?u:a;
    in[u] = a;
    lf[u] = eul.size();
    eul.push_back({lv, u});
    sz[u] = 0;
    for (auto v: edge[u]){
        dfs(v, lv + 1, a);
        sz[u] += sz[v];
        eul.push_back({lv, u});
    }
    sz[u] = sz[u] == 0 ? 1 : sz[u];
}

void init(int l, int r, int i){
    if (l == r - 1){
        mn[i] = eul[l];
        return;
    }
    int m = (l + r) / 2;
    init(l, m, 2 * i + 1);
    init(m, r, 2 * i + 2);
    mn[i] = min(mn[2 * i + 1], mn[2 * i + 2]);
}

pair<int, int> gm(int l, int r, int ql, int qr, int i){
    if (l >= ql && qr >= r)
        return mn[i];
    if (l >= qr || ql >= r)
        return {INF, INF};
    int m = (l + r) / 2;
    return min(gm(l, m, ql, qr, 2 * i + 1), gm(m, r, ql, qr, 2 * i + 2));
}

int lca(int a, int b){
    if (a == -1) return b;
    if (b == -1) return a;
    int l = lf[a];
    int r = lf[b];
    if (l > r) swap(l, r);
    r++;
    return gm(0, eul.size(), l, r, 0).second;
}

vector<pair<int, int> > vt;
vector<int> q;
int pr[1600001];
int nx[1600001];
int ls[1600001];
int sum = 0;
int ct = 0;
int ct1 = 0;

void add(int x){
    ct1++;
    int z = in[x];
    vt.push_back({z, lc[z]});
    sum -= sz[lc[z]];
    ct += (lc[z] == -1);
    lc[z] = lca(x, lc[z]);
    sum += sz[lc[z]];
}

void rev(){
    ct1--;
    auto p = vt.back();
    vt.pop_back();
    int z = p.first;
    sum -= sz[lc[z]];
    lc[z] = p.second;
    ct -= (lc[z] == -1);
    sum += sz[lc[z]];
}

void doit(int l, int r){
    if (l == r - 1){
        if (q[l] == 0){
            cout << ct << " " << sum - ct1 << "\n";
        }
        return;
    }
    int m = (l + r) / 2;
    for (int i = m; i < r; i++)
        if (q[i] < 0 && pr[i] < l)
            add(-q[i]-1);
    doit(l, m);
    for (int i = m; i < r; i++)
        if (q[i] < 0 && pr[i] < l)
            rev();
    for (int i = l; i < m; i++)
        if (q[i] > 0 && nx[i] >= r)
            add(q[i]-1);
    doit(m, r);
    for (int i = l; i < m; i++)
        if (q[i] > 0 && nx[i] >= r)
            rev();
}

int main()
{
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++){
        ls[i] = -1;
        lc[i] = -1;
        int p;
        cin >> p;
        p--;
        edge[p].push_back(i);
    }
    ls[n] = -1;
    dfs(0, 0, 0);
    init(0, eul.size(), 0);
    for (int i = 0; i < k; i++){
        string s;
        int x;
        cin >> s >> x;
        pr[q.size()] = ls[x];
        if (ls[x] >= 0)
            nx[ls[x]] = q.size();
        nx[q.size()] = INF;
        ls[x] = q.size();
        if (s == "+"){
            q.push_back(x);
        }
        else{
            q.push_back(-x);
        }
        q.push_back(0);
    }
    doit(0, q.size());
    return 0;
}

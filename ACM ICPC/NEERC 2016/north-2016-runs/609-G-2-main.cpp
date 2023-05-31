#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define forab(i,a,b) for( int i = (a); i < (b); i++)
#define forn(i,n) forab(i,0,n)

const int MXN = 100100;
const int MXK = 20;

int up [MXN][MXK];
int leafs [MXN];
vector<int> ed [MXN];
vector<int> ed1 [MXN];

int tt [MXN*4];
int mod [MXN*4];

int rgt [MXN];

pii bord [MXN];

int T = 0;
int nnm [MXN];
int tin [MXN];
int tout [MXN];

void dfs1(int v){
    nnm[v] = T++;
    int szz = ed1[v].size();
    forn(i,szz){
        int to = ed1[v][i];
        dfs1(to);
        ed[nnm[v]].pb(nnm[to]);
    }
}

void dfs(int v, int p){
    tin[v] = T++;
    up[v][0] = p;
    forab(i,1,MXK){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    int szz = ed[v].size();
    leafs[v] = (szz == 0 ? 1 : 0);
    rgt[v] = v;
    forn(i,szz){
        int to = ed[v][i];
        dfs(to, v);
        leafs[v] += leafs[to];
        rgt[v] = max(rgt[v], rgt[to]);
    }
    tout[v] = T++;
}
bool upper(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}
int lca(int a, int b){
    if(upper(a,b)) return a;
    if(upper(b,a)) return b;

    for(int i = MXK-1; i >= 0; i--){
        if(!upper(up[a][i], b)){
            a = up[a][i];
        }
    }
    return up[a][0];
}

void build(int tv, int tl, int tr){
    tt[tv] = -1;
    mod[tv] = -2;
    int tm = (tl+tr) / 2;
    if(tl==tr)
        return;
    build(tv*2 + 1, tl, tm);
    build(tv*2 + 2, tm+1, tr);
}
void push(int tv){
    if(mod[tv] == -2){
        return;
    }
    tt[tv] = mod[tv];
    if(tv*2+1 < 4*MXN) mod[tv*2+1] = mod[tv];
    if(tv*2+2 < 4*MXN) mod[tv*2+2] = mod[tv];
    mod[tv] = -2;
}
int get(int tv, int tl, int tr, int i){
    push(tv);
    if(tl==tr){
        return tt[tv];
    }

    int tm = (tl+tr) / 2;
    if (i <= tm){
        return get(tv*2 + 1, tl, tm, i);
    }
    else{
        return get(tv*2 + 2, tm+1, tr, i);
    }
}
void sett(int tv, int tl, int tr, int l, int r, int val){
    push(tv);
    if(tl==l && tr==r){
        mod[tv] = val;
        push(tv);
        return;
    }

    int tm = (tl+tr) / 2;
    if(r <= tm){
        sett(tv*2 + 1, tl, tm, l, r, val);
    }
    else if(l > tm){
        sett(tv*2 + 2, tm+1, tr, l, r, val);
    }
    else{
        sett(tv*2 + 1, tl, tm, l, tm, val);
        sett(tv*2 + 2, tm+1, tr, tm+1, r, val);
    }
}

int disabled = 0;
int pipes = 0;

set<int> gang_f;
set<int, greater<int> > gang_b;

int n;

void add_g(int v){
    gang_f.insert(v);
    gang_b.insert(v);

    int qq = get(0, 0, n-1, v);
    if(qq != -1){
        if(bord[qq].fi > v) bord[qq].fi = v;
        if(bord[qq].se < v) bord[qq].se = v;
        return;
    }
    auto prv = gang_b.upper_bound(v);
    auto nxt = gang_f.upper_bound(v);
    int prev = (prv == gang_b.end() ? -1 : *prv);
    int next = (nxt == gang_f.end() ? -1 : *nxt);
    int pv = 0;
    if(prev != -1){
        pv = lca(prev, v);
        if(pv != 0){
            int prev_pv = get(0, 0, n-1, prev);
            sett(0, 0, n-1, pv, rgt[pv], pv);
            bord[pv] = mp(bord[prev_pv].fi, v);
            disabled -= leafs[prev_pv];
            disabled += leafs[pv];
            return;
        }
    }
    if(next != -1){
        pv = lca(next, v);
        if(pv != 0){
            int prev_pv = get(0, 0, n-1, next);
            sett(0, 0, n-1, pv, rgt[pv], pv);
            bord[pv] = mp(v, bord[prev_pv].se);
            disabled -= leafs[prev_pv];
            disabled += leafs[pv];
            return;
        }
    }
    pipes++;
    disabled++;
    bord[v] = mp(v,v);
    sett(0, 0, n-1, v, v, v);
}
void del_g(int v){
    int pv = get(0, 0, n-1, v);
    if(pv == v){
        sett(0, 0, n-1, v, v, -1);
        disabled--;
        pipes--;
    }
    else if(v == bord[pv].fi){
        int next = *gang_f.upper_bound(v);
        int npv = lca(next, bord[pv].se);
        sett(0, 0, n-1, pv, rgt[pv], -1);
        sett(0, 0, n-1, npv, rgt[npv], npv);
        bord[npv] = mp(next, bord[pv].se);
        disabled -= leafs[pv];
        disabled += leafs[npv];
    }
    else if(v == bord[pv].se){
        int prev = *gang_b.upper_bound(v);
        int npv = lca(bord[pv].fi, prev);
        sett(0, 0, n-1, pv, rgt[pv], -1);
        sett(0, 0, n-1, npv, rgt[npv], npv);
        bord[npv] = mp(bord[pv].fi, prev);
        disabled -= leafs[pv];
        disabled += leafs[npv];
    }
    gang_b.erase(v);
    gang_f.erase(v);
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("gangsters.in", "r", stdin); freopen("gangsters.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> n >> q;

    forn(i,n-1){
        int t;
        cin >> t;
        ed1[t-1].pb(i+1);
    }
    dfs1(0);
    build(0,0,n-1);

    T = 0;
    dfs(0, 0);

    int gangsters = 0;

    forn(i,q){
        char c;
        int v;
        cin >> c >> v;
        v = nnm[v-1];
        if(c=='+'){
            add_g(v);
            gangsters++;
        }
        else{
            del_g(v);
            gangsters--;
        }
        cout << pipes << ' ' << disabled - gangsters << endl;
    }

    return 0;
}

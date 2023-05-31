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

const int maxn = 1e5 + 10;

int a[maxn], b[maxn];


pair <int, int> need[maxn];

vector <vector <int> > g;

vector <int> tp;

bool used[maxn];

void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        if (!used[g[v][i]])
            dfs1(g[v][i]);
    }
    tp.push_back(v);
}


int num = 0;

int sum = 0;

int ans[maxn];

vector <int> cmp;

void dfs2(int v) {
    used[v] = true;
    cmp.push_back(v);
    for (int i = 0; i < g[v].size(); i++) {
        if (!used[g[v][i]])
            dfs2(g[v][i]);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("codecoder.in", "r", stdin); freopen("codecoder.out", "w", stdout);

    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        need[i] = {a[i], i};
    }

    sort(need, need + n);
    for (int i = 1; i < n; i++) {
        g[need[i].se].push_back(need[i - 1].se);
    }
    for (int i = 0; i < n; i++) {
        need[i] = {b[i], i};
    }
    sort(need, need + n);
    for (int i = 1; i < n; i++) {
        g[need[i].se].push_back(need[i - 1].se);
    }

    dfs1(need[n - 1].se);

    for (int i = 0; i < n; i++)
        used[i] = false;

    for (int i = 0; i < tp.size(); i++) {
        if (!used[tp[i]]) {
            dfs2(tp[i]);
            sum += cmp.size();
            for (int i = 0; i < cmp.size(); i++) {
                ans[cmp[i]] = sum - 1;
            }
            cmp.clear();
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';

    return 0;
}

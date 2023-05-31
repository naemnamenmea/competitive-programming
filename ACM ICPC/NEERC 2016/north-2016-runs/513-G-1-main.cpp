#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second

const int maxn = (1e5) + 100;

int branch[maxn];
int child[maxn];
int dirty_branch[maxn];
set <int> gang[maxn];

vector <int> e[maxn];
int dfs(int v){
    if (e[v].size() == 0){
        child[v] = 1;
        return 1;
    }

    int res = 0;
    rep(i, e[v].size()){
        res += dfs(e[v][i]);
    }
    child[v] = res;
    return res;
}

void dfs2(int v, int br){
    branch[v] = br;
    rep(i, e[v].size())
        dfs2(e[v][i], br);
    return;
}

vector <int> p;
int in[maxn];
int deep[maxn];

void dfs3(int v, int de){
    deep[v] = de;
    in[v] = p.size();
    p.push_back(v);
    rep(i, e[v].size()){
        dfs3(e[v][i], de + 1);
        p.push_back(v);
    }
    return;
}

pii tr[maxn * 10];
void build(int i, int l, int r){
    if (l == r - 1){
        tr[i] = mp(deep[p[l]], p[l]);
        return;
    }

    int m = (r + l) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m, r);
    tr[i] = min(tr[2 * i + 1], tr[2 * i + 2]);
    return;
}

pii _get(int i, int l, int r, int u, int v){
    if (l >= v || r <= u){
        return mp(1e9, 1e9);
    }
    if (l >= u && r <= v){
        return tr[i];
    }

    int m = (l + r) / 2;
    return min(_get(2 * i + 1, l, m, u, v), _get(2 * i + 2, m, r, u, v));
}

int LCA(int v, int u){

    int iv = in[v];
    int iu = in[u];

    if (iv > iu)
        swap(iv, iu);

    return _get(0, 0, p.size(), iv, iu + 1).se;
}

int main()
{
    freopen("gangsters.in", "r", stdin);
    freopen("gangsters.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    rep(i, n - 1){
        int x;
        cin >> x;
        e[x].push_back(i + 2);
    }

    dfs(1);

    rep(i, e[1].size())
        dfs2(e[1][i], e[1][i]);

    dfs3(1, 0);
    build(0, 0, p.size());

    int ans = 0;
    int ver = 0;
    rep(i, q){
        string s;
        cin >> s;
        int x;
        cin >> x;

        if (s == "+"){
            int br = branch[x];
        //    cout << "BR " << br << endl;
            if (dirty_branch[br] == 0){
                dirty_branch[br] = x;
                gang[br].insert(x);
                ans++;
                cout << ans << " " << ver << endl;
                continue;
            } else {
                int dir = dirty_branch[br];
                int acc = LCA(dir, x);
          //      cout << "DIR : LCA " << dir << " : " << acc<< endl;
         //       cout << "CHILD " << child[dir] << " " << child[acc] << endl;
                if (dir == acc){
                    ver--;
                    gang[br].insert(x);
                    cout << ans << " " << ver << endl;
                    continue;
                } else {
                    ver -= child[dir];
                    ver += child[acc];
                    ver--;
                    gang[br].insert(x);
                    dirty_branch[br] = acc;
                    cout << ans << " " << ver << endl;
                    continue;
                }
            }

        } else {
            int br = branch[x];
            if (dirty_branch[br] == x){
                dirty_branch[br] = 0;
                gang[br].erase(x);
                ans--;
                cout << ans << " " << ver << endl;
                continue;
            } else {
                int dir = dirty_branch[br];
                gang[br].erase(x);
                if (gang[br].size() == 1){
                    ver -= child[dir] - 2;
                    dirty_branch[br] = *(gang[br].begin());
                    cout << ans << " " << ver << endl;
                    continue;
                } else {
                    int acc = *(gang[br].begin());
                    for (auto v: gang[br])
                        acc = LCA(acc, v);
                    ver -= child[dir];
                    ver += child[acc];
                    ver++;
                    cout << ans << " " << ver << endl;
                    continue;
                }
            }
        }

    }


    return 0;
}
/*

7 6
1 2 1 3 3 3
+ 4
+ 5
+ 6
+ 7
- 6
- 5



8 6
1 2 2 4 4 6 6
+ 8
+ 7
- 7
+ 3
+ 7
- 3

*/

#include <bits/stdc++.h>

using namespace std;
                   
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator << (ostream& cout, pii x) {
	cout << x.first << ' ' << x.second;
	return cout;
}

int n, m;
int color[100005];
set<pii> G[100005];
int cl;
vector<int> g[100005];
int hth[100005];
int cnt[100005];
vector<pii> tree, d;
int pos[100005];
int magic;
pii inf (1e9, 1e9);  
int C, H;
char was[100005];
int counter[100005];
int rt[100005];

void add (int v) {
	counter[color[v]]++;
	if (was[color[v]]) return;
	was[color[v]] = 1;
	C++;
}

void erase (int v) {
	counter[color[v]]--;
	if (!counter[color[v]]) {
		was[color[v]] = 0;
		C--;
	}
}

void dfs (int v, int h = 1) {
	hth[v] = h;
	color[v] = cl;
	pos[v] = (int) d.size ();
	d.pb (mp (h, v));

	if (g[v].empty ())
		cnt[v] = 1;

    for (auto to : g[v]) {
		dfs (to, h + 1);
		d.pb (mp (h, v));
		cnt[v] += cnt[to]; 		   	
    }    	
}

void build () {
	magic = 1;
	while (magic < (int) d.size ())
		magic <<= 1;
	tree.resize (magic << 1, inf);
	for (int i = 0; i < (int) d.size (); i++) {
		tree[i + magic] = d[i];
	}
	for (int i = magic - 1; i > 0; i--) {
		tree[i] = min (tree[i << 1], tree[i << 1 | 1]);
	}
}

pii get (int v, int Tl, int Tr, int l, int r) {
	if (l > r) return inf;
	if (Tl == l && Tr == r)
		return tree[v];
	int M = Tl + Tr;
	M >>= 1;
	v <<= 1;
	return min (get (v, Tl, M, l, min (r, M)), get (v | 1, M + 1, Tr, max (M + 1, l), r));
}

inline pii get (int l, int r) {
	return get (1, 0, magic - 1, l, r);
}

int lca (int a, int b) {
	a = pos[a];
	b = pos[b];
	if (a > b) swap (a, b);       
	return get (a, b).second;
}

int getCnt (int clr) {
	if (G[clr].empty ())
		return 0;

	auto L = *G[clr].begin ();
	auto R = *G[clr].rbegin ();

	int v1 = L.second;
	int v2 = R.second;
                                                                        
	int v3 = lca (v1, v2);

	return cnt[v3] - G[clr].size ();
}

int main () {                   
	freopen ("gangsters.in", "r", stdin);
	freopen ("gangsters.out", "w", stdout);

	cin >> n >> m;

	for (int i = 2, a; i <= n; i++) {
		cin >> a;
		g[a].pb (i);
	}

	for (auto to : g[1]) {
		dfs (to);
		rt[cl] = to;
		cl++;
	}

	build ();
                          
	string cmd;

	cin.tie (0);

	for (int i = 0, v; i < m; i++) {
		 cin >> cmd >> v;         
         H -= getCnt (color[v]);
		 if (cmd[0] == '+') {
		 	add (v);
		 	G[color[v]].insert (mp (pos[v], v));     
		 }
		 else {
			erase (v);
			G[color[v]].erase (mp (pos[v], v));		 	
		 }
		 H += getCnt (color[v]);
		 cout << C << ' ' << H << '\n';
	} 

	return 0;
}
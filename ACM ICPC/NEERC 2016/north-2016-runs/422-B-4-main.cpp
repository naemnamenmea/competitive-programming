#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 2e5;

int n, q, up[N][20];
int tin[N], tout[N], timer;
int w[N], tree[N];
int euler[N];
set < pair<int, int> > s[N];
vector<int> g[N];

int c, h;



void dfs(int v, int p, int num) {
	up[v][0] = p;
	tree[v] = num;
	tin[v] = timer++;
	for (int i = 1; i < 20; ++i) {
		up[v][i] = up[ up[v][i-1] ][i-1];
	}
	for (auto& to : g[v]) {
		if (to != p) {
			dfs(to, v, num);
			w[v] += w[to];
		}
	}
	if (g[v].size() == 1) {
		w[v]++;
	}
	tout[v] = timer++;
}

int pred(int v, int u) {
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int v, int u) {
	if (pred(v, u)) return v;
	if (pred(u, v)) return u;
	int a = v;
	for (int i = 19; i >= 0; --i) {
		if (!pred(up[a][i], u)) {
			a = up[a][i];
		}
	}
	return up[a][0]; 
}

int blocked[N];

void init(int cur) {
	if (blocked[cur] != -1) {
		--c;
		h -= (w[blocked[cur]] - s[cur].size());
		blocked[cur] = -1;
	}
}

void recalc(int cur) {
	if (s[cur].empty()) {
		blocked[cur] = -1;
	} else {
		int v = (*s[cur].begin()).second;
		auto it = s[cur].end();
		--it;
		int u = (*it).second;
		blocked[cur] = lca(v, u);
		++c;
		h += (w[blocked[cur]] - s[cur].size());
	}
}

void add(int v) {
	int cur = tree[v];
	init(cur);
	s[cur].insert(make_pair(tin[v], v));
	recalc(cur);
}

void rm(int v) {
	int cur = tree[v];
	init(cur);
	s[cur].erase(make_pair(tin[v], v));
	recalc(cur);
}

void solve() {
	int n, q;
	cin >> n >> q;
	fill(blocked, blocked + n, -1);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		g[i].push_back(p);
		g[p].push_back(i);
	}
	tin[0] = timer++;
	for (int i = 0; i < g[0].size(); ++i) {
		int to = g[0][i];
		dfs(to, 0, i);
	}
	tout[0] = timer++;
	while (q--) {
		char type;
		int v;
		cin >> type >> v;
		--v;
		if (type == '+') {
			add(v);
		} else {
			rm(v);
		}
		cout << c << ' ' << h << '\n';
	}
}

int main()
{
#ifdef KOBRA
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	freopen("gangsters.in", "r", stdin);
	freopen("gangsters.out", "w", stdout);
#endif // KOBRA
	solve();
    return 0;
}

#include <bits/stdc++.h>



using ll = long long;
using ld = long double;

#define mp make_pair
#define pb push_back

#define filename "gangsters"

using namespace std;

const int maxn = 1e5 + 100;
const int maxk = 18;

int tin[maxn], tout[maxn];
int parent[maxn][maxk];
int timer = 0;
int leafs[maxn];
int proot[maxn];
vector < int > g[maxn];
bool used[maxn];
int realroots[maxn];
int localdel = 0;
set < int > gangs[maxn];
set < int > edges;
int cnt_g = 0;

struct Fenwik {

	Fenwik() : Fenwik(2 * maxn){}

	Fenwik(int n) : n(n) {
		a.resize(n + 1);
	}
	void add(int p, int val) {
		for (; p < n; p |= (p + 1))
			a[p] += val;		
	}

	int sum(int p) {
		int ret = 0;
		for (; p > 0; p = (p & (p + 1)) - 1) {
			ret += a[p];
		}
		return ret;
	}

	int n = 0;
	vector < int > a;
};

Fenwik fen;

void dfs(int v, int p = 0, int ner = 0) {
	used[v] = true;
	proot[v] = ner;
	parent[v][0] = p;
	tin[v] = ++timer;
	for (int i = 1; i < maxk; ++i) {
    	parent[v][i] = parent[parent[v][i - 1]][i - 1];		
	}
	bool leaf = true;
	for (auto u : g[v]) {
		if (!used[u]) {
			leaf = false;
			if (ner == 0)			
				dfs(u, v, u);
			else
				dfs(u, v, ner);
			leafs[v] += leafs[u];
		}
	}
	tout[v] = ++timer;
	leafs[v] += (int)leaf;
}

bool upper(int a, int b) {
	return (tin[a] <= tin[b] && tout[b] <= tout[a]);
}

int lca(int a, int b) {
	if (upper(a, b))
		return a;
	if (upper(b, a))
		return b;
	for (int i = 17; i >= 0; i--) {
		if (!upper(parent[a][i], b)) {
			a = parent[a][i];
		}
	}
	return parent[a][0];
}

void update(int pr) {
	int prev_r = realroots[pr];
	if (prev_r != -1) {
		localdel -= leafs[prev_r];
	}
	if (gangs[pr].size() == 0) {
		edges.erase(pr);
		realroots[pr] = -1;
		return;
	}
	auto v = *gangs[pr].begin();
	int su = fen.sum(tout[pr]) - fen.sum(tin[pr] - 1);
//	cerr << "sums in trree " << su << endl;
	int cu = v;
	for (int i = 17; i >= 0; i--) {
		int mc = parent[cu][i];
		if (upper(pr, mc)) {
			int val = fen.sum(tout[mc]) - fen.sum(tin[mc] - 1);
//			cerr << val << " " << mc + 1 << endl;
			if (val < su) {
				cu = mc;
//				cerr << "changes to " << mc << endl;
			}
		}
	}
	if (fen.sum(tout[cu]) - fen.sum(tin[cu] - 1) < su) {
		cu = parent[cu][0];
	}
	localdel += leafs[cu];
//	cerr << "new real roots " << cu << endl;
	realroots[pr] = cu;
	edges.insert(pr);
}

void add_gang(int v) {
	int pr = proot[v];
	gangs[pr].insert(v);
	fen.add(tin[v], 1);
	update(pr);
}

void del_gang(int v) {
	int pr = proot[v];
	gangs[pr].erase(v);
	fen.add(tin[v], -1);
	update(pr);
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
	int n = 0;
	int q = 0;
	cin >> n;
	cin >> q;
	for (int i = 1; i < n; ++i) {
		realroots[i] = -1;
		int x = 0;
		cin >> x;
		x--;
		g[i].push_back(x);
		g[x].push_back(i);
	}

	dfs(0);
	while (q--) {
		char ch;
		cin >> ch;
		int v = 0;
		cin >> v;
		v--;
		if (ch == '+') {
			add_gang(v);
			cnt_g++;
		} else {
			del_gang(v);
			cnt_g--;
		}
//		cerr << localdel << endl;
		cout << edges.size() << " " << localdel - cnt_g << "\n";		
	}
	return 0;
}
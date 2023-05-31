#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 200500;
const int INF = (int)2e9;

pair<int, int> tree[4 * N];
set<int> have[N];
vector<int> g[N];
int suck[N];
int ret[N];
int tin[N], tout[N];
int timer = 0;
int own[N];
int sz[N];
int n, q;
int fw[N];

int pos;    
pair<int, int> ar[N];

void build(int ver, int l, int r) {
	if (l == r) {
		tree[ver] = ar[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ver + ver,l , mid);
	build(ver + ver + 1, mid + 1, r);
	tree[ver] = min(tree[ver + ver], tree[ver + ver + 1]);
}

pair<int, int> getMin(int ver, int l, int r, int pl, int pr) {
	if (pl > pr) return mp(INF, INF);
	if (l == pl && r == pr) return tree[ver];
	int mid = (l + r) >> 1;
	return min(getMin(ver + ver, l, mid, pl, min(pr, mid)), getMin(ver + ver + 1, mid + 1, r, max(pl, mid + 1), pr));
}

void update(int pos, int add) {
	while (pos <= n) {
		fw[pos] += add;
		pos |= (pos + 1);
	}
}

int get(int r) {
	int ret = 0;
	while (r > 0) {
		ret += fw[r];
		r = (r & (r + 1)) - 1;
	}
	return ret;
}

int lv[N];

void dfs(int ver, int prev, int d, int who) {
	ar[++pos] = mp(d, ver);
	suck[ver] = pos;
	sz[ver] = 1;
	own[ver] = who;
	int gone = 0;
	lv[ver] = 0;
	for (int i = 0; i < (int)g[ver].size(); i++) {
		int to = g[ver][i];
		if (to != prev) {
			gone++;
			dfs(to, ver, d + 1, who);
			sz[ver] += sz[to];
			ar[++pos] = mp(d, ver);
			lv[ver] += lv[to];
		}
	}
	if (gone == 0) lv[ver] = 1;
	tout[ver] = timer;
}

int dick[N];
int pid[N];

int main() {
    freopen("gangsters.in","r",stdin);
    freopen("gangsters.out","w",stdout);
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++) {
    	int x;
    	scanf("%d", &x);
    	g[i].pb(x);
    	g[x].pb(i);
    	if (i == n) scanf("\n");
    }         
    for (int i = 0; i < (int)g[1].size(); i++) {
    	dfs(g[1][i], 1, 1, i + 1);
    } 
    build(1, 1, pos);
    int all = (int)g[1].size();
    int nikita = 0;
    int result = 0;
    for (int i = 1; i <= all; i++) {
    	ret[i] = 0;
    	pid[i] = 0;
    	have[i].clear();
    }
    set<int> :: iterator it;
    char type;
    int v;
    for (int i = 1; i <= q; i++) {
    	scanf("%c", &type);
    	scanf("%d", &v);
    	int le = tin[v] + 1;
    	int ri = tout[v];
    	int id = own[v];
    	result -= ret[id];
    	if (type == '+') {
    		dick[v] = 1;
    		if (lv[v] == 1) pid[id]++;
    		if (have[id].size() == 0) nikita++;
			have[id].insert(suck[v]);
		} else {
			dick[v] = 0;
			if (lv[v] == 1) pid[id]--;
			have[id].erase(have[id].find(suck[v]));
		}
		if (have[id].size() == 0) {
			--nikita;
			ret[id] = 0;
		} else {
			it = have[id].begin();
			le = *it;
			it = have[id].end(); --it;
			ri = *it;
			pair<int, int> para = getMin(1, 1, pos, le, ri);
			ret[id] = lv[para.S] - pid[id];
			result += ret[id];
		}     	
    	printf("%d %d\n", nikita, result);
    	if (i < q) scanf("\n");
    }
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 2000500;

int n;
int vers[N];
int col[N];
int sz[N];
int a[N], b[N];
bool used[N];
vector<int> g[N], gr[N];
set<int> gg[N];

void add(int x, int y) {
	g[x].pb(y);
	gr[y].pb(x);
}

vector<int> mda;

void dfsTop(int ver) {
	used[ver] = true;
	for (int i = 0; i < (int)g[ver].size(); i++) {
		int to = g[ver][i];
		if (!used[to]) {
			dfsTop(to);
		}
	}
	mda.pb(ver);
}

void dfs(int ver, int o) {
	col[ver] = o;
	vers[o]++;
	for (int i = 0; i < (int)gr[ver].size(); i++) {
		int to = gr[ver][i];
		if (col[to] == -1) {
			dfs(to, o);
		}
	}           
}
                              
void solve(int ver) {
	used[ver] = true;
	sz[ver] = vers[ver];
	for (set<int> :: iterator it = gg[ver].begin(); it != gg[ver].end(); it++) {
		if (!used[*it]) solve(*it);
		sz[ver] += sz[*it];
	}
}	

int main() {
    freopen("codecoder.in","r",stdin);
    freopen("codecoder.out","w",stdout);
    scanf("%d", &n);
    vector< pair<int, int> > va, vb;
    for (int i = 1; i <= n; i++) {
    	scanf("%d%d", &a[i], &b[i]);
		va.pb(mp(a[i], i));
		vb.pb(mp(b[i], i));
		vers[i] = 0;
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	for (int i = n - 1; i > 0; --i) {
		add(va[i].S, va[i - 1].S);
		add(vb[i].S, vb[i - 1].S); 
	}    	          
	for (int i = 1; i <= n; i++) used[i] = false;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) dfsTop(i);
	}
	reverse(mda.begin(), mda.end());
	int cols = 0;
	for (int i = 1; i <= n; i++) col[i] = -1;
	for (int i = 0; i < (int)mda.size(); i++) {
		if (col[mda[i]] == -1) {
			++cols;
			dfs(mda[i], cols);	
		} 
	}                
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (int)g[i].size(); j++) {
			int to = g[i][j];
			to = col[to];
			int u = col[i];
			if (u != to) {
				gg[u].insert(to);
			//	cout << u << " " << to << endl;
			}
		}
	}
	for (int i = 1; i <= n; i++) used[i] = false;
	for (int i = 1; i <= cols; i++) {
		if (!used[i]) solve(i);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", sz[col[i]] - 1);
	}
	return 0;
}
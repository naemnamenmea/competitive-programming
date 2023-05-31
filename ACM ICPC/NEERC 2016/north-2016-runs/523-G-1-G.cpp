#define FNAME "gangsters"

#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);++i)
#define forit(i,V) for(__typeof(V.begin()) i=V.begin();i!=V.end();++i)
#define fornr(i,N) for(int i=int(N)-1;i>=0;--i)
#define forab(i,a,b) for(int i=(a);i<int(b);++i)
#define all(V) (V).begin(),(V).end()
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define sz(V) (int)((V).size())

typedef long long LL;
typedef pair<int,int> pii;
typedef long double LD;
typedef vector<int> vi;

const int N = 1e5 + 200;
const int LOG = 18;

vector <int> g[N];
int size[N], seg[N], p[N][LOG], tin[N], tout[N], tim;
set <int> s[N];

int dfs(int v, int c, int par) {
	seg[v] = c;
	p[v][0] = par;
	forab(i, 1, LOG) {
		p[v][i] = p[p[v][i - 1]][i - 1];
	}
	if (sz(g[v]) == 0)
		size[v] = 1;
	tin[v] = tim++;
	for (int to : g[v]) {
		size[v] += dfs(to, c, v); 
	}
	tout[v] = tim++;
	return size[v];
}

bool upper(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
	if (upper(v, u))
		return v;
	if (upper(u, v))
		return u;
	fornr(i, LOG) {
		if (!upper(p[v][i], u))
			v = p[v][i];	
	}
	return p[v][0];
}

pii get_ans(int id) {
	if (s[id].empty()) {
		return mp(0, 0);
	}
	int v = lca(*s[id].begin(), *s[id].rbegin());
	return mp(1, size[v] - sz(s[id]));
}

int main(){
	assert(freopen(FNAME".in","r",stdin));
	assert(freopen(FNAME".out","w",stdout));
	int n, q;
	cin >> n >> q;
	forn(i, n - 1) {
		int par; cin >> par;
		g[par - 1].pb(i + 1);		
	}
	int c = 0;
	for(int to : g[0]) {
		dfs(to, c, to);
		c++;
	}
	pii ans = mp(0, 0);
	forn(i, q) {
		char ch;
		int v;
		cin >> ch >> v;
		v--;
		pii last = get_ans(seg[v]);
		if (ch == '+')
			s[seg[v]].insert(v);
		else
			s[seg[v]].erase(v);
		pii nxt = get_ans(seg[v]);
		ans.fst = ans.fst - last.fst + nxt.fst;
		ans.snd = ans.snd - last.snd + nxt.snd;
		cout << ans.fst << " " << ans.snd << '\n';
	}
	
	return 0;
}
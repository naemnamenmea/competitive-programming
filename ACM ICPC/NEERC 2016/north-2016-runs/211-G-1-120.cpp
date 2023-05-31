#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
#define mk make_pair
#define forn(i, n) for(ll i = 0; i < (ll)(n); i++)
#define fornn(i, a, n) for(ll i = (ll)(a); i < (ll)(n); i++)

const int dd = 3e5 + 7;
const int Log = 20;

int up[dd][Log], dp[dd], sum = 0;
int in[dd], out[dd], ti = 0;
vector<int> P[dd];

int n, q;

void dfs(int v, int p){
	up[v][0] = p;
	for (int i = 1; i < Log; i++){
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	in[v] = ti++;
	if(P[v].size() == 0) dp[v] = 1;
	forn(i, P[v].size()){
		dfs(P[v][i], v);
		dp[v] += dp[P[v][i]];
	}
	out[v] = ti++;
}

bool is(int a, int b){
	return in[a] <= in[b] && out[b] <= out[a];
}

int lca(int a, int b){
	if (is(a, b)){
		return a;
	}
	if (is(b, a)){
		return b;
	}
	for (int i = Log - 1; i >= 0; i--){
		int t = up[a][i];
		if (!is(t, b)){
			a = t;
		}
	}
	return up[a][0];
}

vector<int> C;

void dfs2(int v, int c){
	C[v] = c;
	forn(i, P[v].size()){
		dfs2(P[v][i], c);
	}
}

set<pair<int, int> > Q;
set<pair<int, int> > W[dd];
int main(){
	if (0){
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else{
		freopen("gangsters.in", "r", stdin);
		freopen("gangsters.out", "w", stdout);
	}
	cin >> n >> q;
	C.resize(n);
	forn(i, n - 1){
		int t;
		cin >> t;
		P[t - 1].push_back(i + 1);
	}
	int g = P[0].size();
	dfs(0, 0);
	forn(i, g){
		dfs2(P[0][i], i);
	}
	int er = 0;
	sum = 0;
	forn(i, q){
		char c;
		int v;
		cin >> c >> v;
		v--;
		int b = C[v];
		if (W[b].size()){
			int a = W[b].begin()->second;
			int e = W[b].rbegin()->second;
			sum -= dp[lca(a, e)];
		}

		if (c == '+'){	
			if (W[b].size() == 0){
				er++;
			}
			W[b].insert(mk(in[v], v));
			Q.insert(mk(in[v], v));

		}
		else{
			if (W[b].size() == 1){
				er--;
			}
			W[b].erase(mk(in[v], v));
			Q.erase(mk(in[v], v));
		}
		if (W[b].size()){
			int a = W[b].begin()->second;
			int e = W[b].rbegin()->second;
			sum += dp[lca(a, e)];
		}
		int Gg = -1;
		
		if (Q.size()){
			int a = Q.begin()->second;
			int e = Q.rbegin()->second;
			Gg = lca(a, e);
		}
		if (Gg == 0){
			cout << er << ' ' << sum - (int)Q.size() << '\n';
		}
		else{
			cout << "1 " << dp[Gg] - (int)Q.size() << '\n';
		}
	}
}

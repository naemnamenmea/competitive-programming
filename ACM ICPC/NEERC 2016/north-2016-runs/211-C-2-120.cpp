#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
#define mk make_pair
#define forn(i, n) for(ll i = 0; i < (ll)(n); i++)
#define fornn(i, a, n) for(ll i = (ll)(a); i < (ll)(n); i++)

const int dd = 2e5 + 7;

vector<int> P[dd], U[dd], W[dd];
int N;

void con(vector<pair<int, int> > A){
	int e = -1;
	int n = A.size();
	map<int, vector<int> > W;
	forn(i, n){
		W[A[i].first].push_back(A[i].second);
	}
	vector<vector<int> > Q;
	for (auto it : W){
		Q.push_back(it.second);
	}
	for (int i = 0; i < (int)Q.size() - 1; i++){
		int e = N++;
		forn(j, Q[i].size()){
			P[e].push_back(Q[i][j]);
		}
		forn(j, Q[i + 1].size()){
			P[Q[i + 1][j]].push_back(e);
		}
	}
}

int T[dd], ti = 1;
vector<int> E;
void dfs(int v){
	if (T[v] == ti){
		return;
	}
	T[v] = ti;
	forn(i, P[v].size()){
		dfs(P[v][i]);
	}
	E.push_back(v);
}

vector<int> C, L, R, Aa, Bb;
vector<int> S;
vector<int> Dp;

void dfs2(int v, int c){
	if (T[v] == ti){
		return;
	}
	T[v] = ti;
	C[v] = c;
	L[c] = max(L[c], Aa[v]);
	R[c] = max(R[c], Bb[v]);
	forn(i, U[v].size()){
		dfs2(U[v][i], c);
	}
}


const int si = dd * 10 + 7;
struct fn{
	int F[si];
	int Ff(int f){
		return f & -f;
	}
	void up(int x, int d){
		for (int i = x + 1; i < si; i += Ff(i)){
			F[i] += d;
		}
	}
	int sum(int x){
		int s = 0;
		for (int i = x + 1; i; i -= Ff(i)){
			s += F[i];
		}
		return s;
	}
} Ee;

vector<pair<int, int> > Z[si];
int main(){
	if (0){
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else{
		freopen("codecoder.in", "r", stdin);
		freopen("codecoder.out", "w", stdout);

	}
	int n;
	cin >> n;
	N = n;
	vector<pair<int, int> > A(n), B(n);
	Aa.resize(n);
	Bb.resize(n);
	forn(i, n){
		cin >> A[i].first >> B[i].first;
		A[i].second = B[i].second = i;
		Aa[i] = A[i].first;
		Bb[i] = B[i].first;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	con(A);
	con(B);
	Aa.resize(N);
	Bb.resize(N);
	forn(i, N){
		forn(j, P[i].size()){
			U[P[i][j]].push_back(i);
		}
	}
	forn(i, N){
		dfs(i);
	}
	reverse(E.begin(), E.end());
	ti++;
	L.resize(N);
	R.resize(N);
	C.resize(N);
	S.resize(N);
	int g = 0;
	forn(i, E.size()){
		if (T[E[i]] != ti){
			dfs2(E[i], g++);
		}
	}
	Dp.resize(n);
	forn(i, N){
		forn(j, P[i].size()){
			if (C[i] != C[P[i][j]]){
				W[C[i]].push_back(C[P[i][j]]);
			}
		}
	}
	for (int i = g - 1; i >= 0; i--){
		forn(j, W[i].size()){
			L[i] = max(L[i], L[W[i][j]]);
			R[i] = max(R[i], R[W[i][j]]);
		}
	}


	forn(i, n){
		Z[Aa[i]].push_back(mk(1e7, Bb[i]));
		Z[L[C[i]]].push_back(mk(i, R[C[i]]));
	}
	forn(i, si){
		sort(Z[i].begin(), Z[i].end());
		forn(j, Z[i].size()){
			auto t = Z[i][j];
			if (t.first > 1e6){
				Ee.up(t.second, 1);
			}
			else{
				Dp[t.first] -= Ee.sum(t.second);
			}
			
		}
	}

	Aa.resize(n);
	Bb.resize(n);
	sort(Aa.begin(), Aa.end());
	sort(Bb.begin(), Bb.end());
	forn(i, n){
		int l = L[C[i]];
		int r = R[C[i]];
		Dp[i] += lower_bound(Aa.begin(), Aa.end(), l) - Aa.begin();
		Dp[i] += lower_bound(Bb.begin(), Bb.end(), r) - Bb.begin();
	}

	forn(i, n){
		cout << Dp[i] << '\n';
	}
}
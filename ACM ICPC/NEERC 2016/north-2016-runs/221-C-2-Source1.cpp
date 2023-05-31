#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define mp make_pair

typedef pair<int, int> pi;

const int MAXN = 1e5 + 10;

vector<int> graph[MAXN];

int clr = 1, color[MAXN], q[MAXN];

void dfs(int v) {
	color[v] = clr;
	q[clr]++;
	for (int i = 0; i < graph[v].size(); ++i) {
		if (!color[graph[v][i]])
			dfs(graph[v][i]);
	}
}

int main(){
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
#endif

	int n;

	vector<pi> vt, vc;
	int cc[MAXN], ct[MAXN];

	cin >> n;

	for (int i = 0; i < n; ++i) {
		color[i] = 0;
		int x, y;
		cin >> x >> y;
		vt.push_back(mp(x, i));
		vc.push_back(mp(y, i));
		cc[i] = y;
		ct[i] = x;
	}

	sort(vc.begin(), vc.end());
	sort(vt.begin(), vt.end());
	
	for (int i = 0; i < vc.size() - 1; ++i) {
		graph[vc[i + 1].second].push_back(vc[i].second);
		graph[vt[i + 1].second].push_back(vt[i].second);
	}

	for (int i = 0; i < n; ++i) {
		if (!color[vc[i].second])
			dfs(vc[i].second);
		clr++;
	}

	for (int i = 2; i < clr; ++i)
		q[i] += q[i - 1];

	for (int i = 0; i < n; ++i)
		cout << q[color[i]] - 1 << endl;

	return 0;
}
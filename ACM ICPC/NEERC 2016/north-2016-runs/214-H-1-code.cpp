#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <assert.h>
#include <memory>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ll long long 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back

int dp[66][66];
int w1[66][66];
int h1[66][66];
int w2[66][66];
int h2[66][66];

int solve(int a, int b) {
	if (dp[a][b] != -1) return dp[a][b];
	if (a == b) return dp[a][b] = 1;
	int res = 1e9;
	for (int i = 1; i < a; i++) {
		int cnt = solve(i, b) + solve(a - i, b);
		if (cnt < res) {
			res = cnt;
			w1[a][b] = i;
			w2[a][b] = a - i;
			h1[a][b] = b;
			h2[a][b] = b;
		}
	}
	for (int i = 1; i < b; i++) {
		int cnt = solve(a, i) + solve(a, b - i);
		if (cnt < res) {
			res = cnt;
			w1[a][b] = a;
			w2[a][b] = a;
			h1[a][b] = i;
			h2[a][b] = b - i;
		}
	}
	return dp[a][b] = res;
}

void getpath(int sx, int sy, int a, int b, vector<pair<pair<int, int>, int> >& ans) {
	if (a == b) {
		ans.pb(mp(mp(sx, sy), a));
		return;
	}
	getpath(sx, sy, w1[a][b], h1[a][b], ans);
	getpath(sx - w2[a][b] + a, sy - h2[a][b] + b, w2[a][b], h2[a][b], ans);
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	freopen("hard.in", "rt", stdin);
freopen("hard.out", "wt", stdout);
	memset(dp, -1, sizeof(dp));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", solve(a, b));
		vector<pair<pair<int, int>, int> > ans;
		getpath(0, 0, a, b, ans);
		for (int j = 0; j < sz(ans); j++) {
			printf("%d %d %d\n", ans[j].first.first, ans[j].first.second, ans[j].second);
		}
	}

	return 0;
}
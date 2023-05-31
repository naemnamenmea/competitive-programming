#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ll long long 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back

int dp[66][66];
int sq[66][66];
bool wtf[66][66];

int solve(int a, int b) {
	if (a <= 0 || b <= 0) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	if (a == b) return dp[a][b] = 1;
	int res = 1e9;
	for (int i = 1; i <= min(a, b); i++) {
		int cnt = 1 + solve(a - i, b) + solve(i, b - i);
		if (cnt < res) {
			res = cnt;
			sq[a][b] = i;
			wtf[a][b] = false;
		}
	}
	for (int i = 1; i <= min(a, b); i++) {
		int cnt = 1 + solve(a - i, i) + solve(a, b - i);
		if (cnt < res) {
			res = cnt;
			sq[a][b] = i;
			wtf[a][b] = true;
		}
	}
	return dp[a][b] = res;
}

void getpath(int sx, int sy, int a, int b, vector<pair<pair<int, int>, int> >& ans) {
	if (a <= 0 || b <= 0) return;
	if (a == b) {
		ans.pb(mp(mp(sx, sy), a));
		return;
	}
	ans.pb(mp(mp(sx, sy), sq[a][b]));
	if (!wtf[a][b]) {
		getpath(sx + sq[a][b], sy, a - sq[a][b], b, ans);
		getpath(sx, sy + sq[a][b], sq[a][b], b - sq[a][b], ans);
	}
	else {
		getpath(sx + sq[a][b], sy, a - sq[a][b], sq[a][b], ans);
		getpath(sx, sy + sq[a][b], a, b - sq[a][b], ans);
	}
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
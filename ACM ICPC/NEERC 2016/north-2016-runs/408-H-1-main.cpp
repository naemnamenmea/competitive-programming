#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define TYPEMIN(type) std::numeric_limits<type>::min()
#define TYPEMAX(type) std::numeric_limits<type>::max()

using namespace std;

vector<vector<int>> dp(61, vector<int>(61));
vector<vector<pair<int, int>>> par(61, vector<pair<int, int>>(61));
void precalc() {
	for (int i = 1; i <= 60; ++i)
		for (int j = 1; j <= 60; ++j)
			if (i == j)
				dp[i][j] = 1, par[i][j] = {0, 0};
			else {
				dp[i][j] = TYPEMAX(int);
				for (int k = 1; k < i; ++k)
					if (dp[i][j] > dp[k][j] + dp[i - k][j])
						 dp[i][j] = dp[k][j] + dp[i - k][j], par[i][j] = {k, j};
				for (int k = 1; k < j; ++k)
					if (dp[i][j] > dp[i][k] + dp[i][j - k])
						dp[i][j] = dp[i][k] + dp[i][j - k], par[i][j] = {i, k};
			}


}

void restore(int w, int h, int x, int y) {
	if (par[w][h] == pair<int, int>{0, 0})
		cout << x << " " << y << " " << w << "\n";
	else {
		auto tmp = par[w][h];
		restore(tmp.first, tmp.second, x, y);
		if (w != tmp.first)
			restore(w - tmp.first, tmp.second, x + tmp.first, y);
		else
			restore(tmp.first, h - tmp.second, x, y + tmp.second);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;

#ifndef LOCAL
#define FILE "hard"
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
#endif

	precalc();

	int T;
	cin >> T;
	for (int i = 0; i != T; ++i) {
		int w, h;
		cin >> w >> h;
		cout << dp[w][h] << "\n";
		restore(w, h, 0, 0);
	}

	return 0;
}


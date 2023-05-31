#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

pair<pair<int, int>, pair<int, int>> solve(int w, int h, int ax, int ay, int bx, int by) {
	if (ax != bx) {
		return {{ax, 0}, {bx, h}};
	} else {
		auto ans = solve(h, w, ay, ax, by, bx);
		std::swap(ans.first.first, ans.first.second);
		std::swap(ans.second.first, ans.second.second);
		return ans;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;

#ifndef LOCAL
#define FILE "anniversary"
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
#endif

	int w, h, ax, ay, bx, by;
	cin >> w >> h >> ax >> ay >> bx >> by;

	auto ans = solve(w, h, ax, ay, bx, by);
	cout << ans.first.first << " " << ans.first.second << " " << ans.second.first << " " << ans.second.second << "\n";

	return 0;
}


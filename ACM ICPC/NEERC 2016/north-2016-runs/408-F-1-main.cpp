#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int get(int a, int b) {
	int cnt = 0;
	while (a != b) {
		if ((a + 1) / 2 > b) {
			a = (a + 1) / 2;
		} else {
			a = b;
		}
		cnt++;
	}
	return cnt;
}

int check(int W, int H, int w, int h) {
	if (W < w || H < h)
		return INF;
	return get(W, w) + get(H, h);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;

#ifndef LOCAL
#define FILE "folding"
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
#endif

	int W, H, w, h;
	cin >> W >> H >> w >> h;
	int best = min(check(W, H, w, h), check(W, H, h, w));
	if (best == INF)
		best = -1;
	cout << best;

	return 0;
}


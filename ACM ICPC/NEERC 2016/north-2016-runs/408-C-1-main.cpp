#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define TYPEMIN(type) std::numeric_limits<type>::min()
#define TYPEMAX(type) std::numeric_limits<type>::max()

using namespace std;

const int MAXN = 2e5;
const int MAXC = 2e6;

struct Point {
	int x, y;
	int id;
	bool operator <(const Point &other) const {
		if (x != other.x)
			return x < other.x;
		if (y != other.y)
			return y < other.y;
		return id < other.id;
	}
};

int n;
Point pt[MAXN];
int maxX[MAXC], maxY[MAXC];
int cnt[MAXC];
int ans[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;

#ifndef LOCAL
#define FILE "codecoder"
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pt[i].x >> pt[i].y;
		maxX[pt[i].y] = max(maxX[pt[i].y], pt[i].x);
		maxY[pt[i].x] = max(maxY[pt[i].x], pt[i].y);
		cnt[pt[i].x]++;
		pt[i].id = i;
	}
	sort(pt, pt + n);

	for (int i = 1; i < MAXC; i++) {
		maxX[i] = max(maxX[i], maxX[i - 1]);
		maxY[i] = max(maxY[i], maxY[i - 1]);
		cnt[i] += cnt[i - 1];
	}

	int bestX = 0, bestY = 0;
	for (int i = 0; i < n; i++) {
		bestX = max(bestX, pt[i].x);
		bestY = max(bestY, pt[i].y);
		while (true) {
			int succ = 0;
			if (maxY[bestX] > bestY) {
				succ++;
				bestY = maxY[bestX];
			}
			if (maxX[bestY] > bestX) {
				succ++;
				bestX = maxX[bestY];
			}
			if (succ == 0)
				break;
		}
		ans[pt[i].id] = cnt[bestX] - 1;
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';

	return 0;
}


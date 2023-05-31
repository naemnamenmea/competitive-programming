#include <bits/stdc++.h>
#define TASK "anniversary"
using namespace std;

typedef long long ll;


void solve() {
	int W, H;
	int ax, ay, bx, by;
	cin >> W >> H >> ax >> ay >> bx >> by;
	if (ax != bx)
		cout << ax << " " << 0 << " " << bx << " " << H;
	else
		cout << 0 << " " << ay << " " << W << " " << by;
}

int main() {
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	solve();
	return 0;
}
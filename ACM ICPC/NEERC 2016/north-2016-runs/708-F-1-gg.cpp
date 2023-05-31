#include <bits/stdc++.h>
#define TASK "folding"
using namespace std;

typedef long long ll;

int W, H, w, h;

int go(int a, int b) {
	int ans = 0;
	while (a > b) {
		a = a / 2 + (a % 2);
		//cerr << a << "\n";
		ans++;
	}
	return ans;
} 

void solve() {
	cin >> W >> H >> w >> h;
	if (max(W, H) < max(w, h) || min(W, H) < min(w, h)) {
		cout << -1;
		exit(0);
	}
	int ans = INT_MAX;
	ans = min(ans, go(W, w) + go(H, h));
	ans = min(ans, go(W, h) + go(H, w));
	cout << ans;	
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
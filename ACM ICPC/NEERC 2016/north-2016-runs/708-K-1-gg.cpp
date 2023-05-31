#include <bits/stdc++.h>
#define TASK "king"
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair < int, int > pii; 

const int ds[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

vector < pii > gg;
int now;

int getDays(int mm) {
	--mm;
	int ans = 0;
	for (int i = 0; i < mm; i++) {
		ans += ds[i];
	}
	return ans;
}

int n;

bool good(int tt) {
	int q = getDays(13) * 18;
	return (tt >= q);
}

int solve() {
	int a, b, c;
	cin >> a >> b >> c;
	now = getDays(b) + a + getDays(13) * c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		int dd = getDays(b) + a + getDays(13) * c - now;
		gg.pb({ dd, i });
	}
	sort(gg.begin(), gg.end());
	for (int i = n - 1; i >= 0; i--) {
		int id = gg[i].second;
		int tt = gg[i].first;
		if (good(-tt)) {
			cout << id + 1;
			exit(0);
		}
	}
	cout << -1;
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
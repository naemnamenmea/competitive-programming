#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#include <cassert>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 2e5;

void fail() {
	cout << "Impossible\n";
	exit(0);
}

void output(int b1, int b2, int g1, int g2, int boys, int girls) {
	int blocks = b1 + b2;
	assert(b1 + b2 == g1 + g2);
	assert(b1 >= 0 && b2 >= 0 && g1 >= 0 && g2 >= 0);
	assert(b1 + b2 * 2 <= boys);
	assert(g1 + g2 * 2 <= girls);
	assert(blocks > 0);
	assert(b2 > 0 || g2 > 0);
	assert(b2 > 0 || b1 == boys);
	assert(g2 > 0 || g1 == girls);
	string ans = "";
	int n = boys + girls;
	for (int i = 0; i < blocks; ++i) {
		if (b1) {
			ans += "B";
			--boys;
			--b1;
		} else {
			--b2;
			if (i == blocks - 1) {
				assert(boys >= 2 && b2 == 0);
				for (int i = 0; i < boys; ++i) {
					ans += "B";
				}
			} else {
				ans += "BB";
				boys -= 2;
			}
		}
		if (g1) {
			ans += "G";
			--girls;
			--g1;
		} else {
			--g2;
			if (i == blocks - 1) {
				
				assert(girls >= 2 && g2 == 0);
				for (int i = 0; i < girls; ++i) {
					ans += "G";
				}
			} else {
				ans += "GG";
				girls -= 2;
			}
		}
	}
	assert(ans.size() == n);
	cout << ans << '\n';
	exit(0);
}

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	if ((x - y + n) % 2 != 0) {
		fail();
	}
	if ((y - x + n) % 2 != 0) {
		fail();
	}
	
	if (!x) {
		if (y == n) {
			for (int i = 0; i < n; ++i) {
				cout << 'G';
			}
			cout << '\n';
		} else {
			fail();
		}
		return;
	}
	if (!y) {
		if (x == n) {
			for (int i = 0; i < n; ++i) {
				cout << 'B';
			}
			cout << '\n';
		} else {
			fail();
		}
		return;
	}
	
	int boys = (x - y + n) / 2;
	int girls = (y - x + n) / 2;
	int value = x - boys;
	assert(x - boys == y - girls);
	int b1, b2, g1, g2;
	
	if (n % 2 == 0 && x == n / 2 && y == n / 2) {
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				cout << "G";
			} else {
				cout << "B";
			}
		}
		return;
	}
	
	b1 = boys;
	b2 = 0;
	g1 = n - y;
	
	if ((x - g1) % 2 == 0) {
		g2 = (x - g1) / 2;
		if (g2 > 0 && b1 + b2 == g1 + g2 && (girls - g1) >= g2 * 2) {
			output(b1, b2, g1, g2, boys, girls);
		}
	}
	
	g1 = girls;
	g2 = 0;
	b1 = n - x;
	if ((y - b1) % 2 == 0) {
		b2 = (y - b1) / 2;
		if (b2 > 0 && b1 + b2 == g1 + g2 && (boys - b1) >= b2 * 2) {
			output(b1, b2, g1, g2, boys, girls);
		}
	}
	
	
	for (int delta = -n; delta <= n; ++delta) {
		//g1 - b1 = delta
		if (delta < 0) {
			g1 = 0;
			b1 = -delta;
		} else {
			g1 = delta;
			b1 = 0;
		}
		if ((value - delta) % 2 != 0) continue;
		if ((value + delta) % 2 != 0) continue;
		g2 = (value - delta) / 2;
		b2 = (value + delta) / 2;
		if (min(b2, g2) < 1) continue;
		if (b2 - g2 != delta) continue;
		if (boys - b1 < b2 * 2) continue;
		if (girls - g1 < g2 * 2) continue;
		output(b1, b2, g1, g2, boys, girls);
	}
	cout << "Impossible\n";
}

int main() {
#ifdef KOBRA
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#else
	freopen("boysgirls.in", "r", stdin);
	freopen("boysgirls.out", "w", stdout);
#endif // KOBRA

	solve();
	
    return 0;
}

#include <bits/stdc++.h>



using ll = long long;
using ld = long double;

#define mp make_pair
#define pb push_back

#define filename "integral"

using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
	int n = 0;
	cin >> n;
	vector < pair < int, int > > a;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		x = abs(x);
		y = abs(y);
		x %= 2;
		y %= 2;
		a.push_back({x, y});
	//	cerr << a.back().first << " " << a.back().second << endl;
	}
	a.push_back(a[0]);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i].first * a[i + 1].second + a[i + 1].first * a[i].second;
	}
	ans %= 2;
	if (ans == 1) {
		cout << 0;
		return 0;
	}
	vector < int > pref;
	pref.push_back(0);
	for (int i = 1; i < n; i++) {
		pref.push_back(pref.back() + a[i].second * a[i - 1].first + a[i].first * a[i - 1].second);
		pref.back() %= 2;
		assert(pref.back() < 2);
	}
	ans = 0;
	for (int m1 = 0; m1 < 4; m1++) {
		for (int m2 = 0; m2 < 4; m2++) {
			auto p2 = make_pair(m2 / 2, m2 % 2);
			auto p1 = make_pair(m1 / 2, m1 % 2);
			int cnt[2] = {};
			int diag = p1.first * p2.second + p1.second * p2.first;
			diag %= 2;
			for (int i = 0; i < n; i++) {
				if (i > 1) {
					if (a[i] == p2) {
						int want = (pref[i] + diag)	% 2;
						ans += cnt[want];
						if (a[i - 1] == p1 && want == pref[i - 1])
							ans--;
					}
				}				
				if (a[i] == p1) {
					cnt[pref[i]]++;
				}
			}
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
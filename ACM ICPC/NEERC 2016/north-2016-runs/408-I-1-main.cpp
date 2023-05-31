#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define TYPEMIN(type) std::numeric_limits<type>::min()
#define TYPEMAX(type) std::numeric_limits<type>::max()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define PYMOD(a, m) ((((a) % (m)) + (m)) % (m))

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;

#ifndef LOCAL
#define FILE "integral"
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
#endif

	int n;
	cin >> n;

	int x[n], y[n];
	forn(i, n)
		cin >> x[i] >> y[i];

	deque<int> dq[1 << 4];
	ll sum[1 << 4];

	forn(mask, 1 << 4) {
		for (int i = 2; i < n - 1; i++) {
			int a = x[i] % 2;
			int b = y[i] % 2;
			int c = (a << 1) | b;
			if ((mask >> c) & 1) {
				if (dq[mask].size() % 2)
					dq[mask].pb(-i);
				else
					dq[mask].pb(i);
			}
		}
		sum[mask] = 0;
		for (int u : dq[mask])
			sum[mask] += u;
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		int cmask = 0;
		int dx = x[(i + 1) % n] - x[i] % n;
		int dy = y[(i + 1) % n] - y[i] % n;
		forn(a, 2)
			forn(b, 2)
				if ((dx * a + dy * b) % 2 == 0)
					cmask |= (1 << ((1 << a) | b));
		ll to_a = sum[cmask];
		if (dq[cmask].front() > 0)
			to_a = -to_a;
		if (dq[cmask].size() % 2 == 1)
			to_a += n - 1 + i;
		//cout << to_a << endl;
		ans += to_a;


		int a = x[(i + 2) % n] % 2;
		int b = y[(i + 2) % n] % 2;
		int c = (a << 1) | b;
		forn(mask, 1 << 4) {
			if ((mask >> c) & 1) {
				sum[mask] -= dq[mask].front();
				dq[mask].pop_front();
			}
		}

		a = x[PYMOD(i - 1, n)] % 2;
		b = y[PYMOD(i - 1, n)] % 2;
		c = (a << 1) | b;
		forn(mask, 1 << 4) {
			if ((mask >> c) & 1) {
				if (!(dq[mask].size()) || dq[mask].back() > 0)
					dq[mask].pb(-(i + n - 1));
				else
					dq[mask].pb(i + n - 1);
				sum[mask] += dq[mask].back();
			}
		}
	}

	cout << ans / 2 << endl;

	return 0;
}

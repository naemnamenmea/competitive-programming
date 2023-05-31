#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

ll d(ll W, ll H, ll w, ll h) {
	ll d1 = max(0ll, W - w) + max(0ll, H - h);
	ll d2 = max(0ll, W - h) + max(0ll, H - w);
	return min(d1, d2);
}

ll solve(ll W, ll H, ll w, ll h, ll d = 0) {
	//cout << W << " " << H << " " << w << " " << h << " " << ::d(W, H, w, h) << endl;
	if (::d(W, H, w, h) == 0 || d > 30) {
		return d;
	}
	ll d1 = solve(W, H, min(2 * w, W), h, d + 1);
	ll d2 = solve(W, H, w, min(2 * h, H), d + 1);
	return min(d1, d2);
}

int main() {
	const string _cur = "folding"; freopen((_cur + ".in").c_str(), "r", stdin); freopen((_cur + ".out").c_str(), "w", stdout);
	ll W, H, w, h;
	cin >> W >> H >> w >> h;
	ll mm = max(w, h);
	if (! (min(w, h) <= min(W, H) && max(w, h) <= max(W, H)) ) {
		cout << -1;
		return 0;
	}
	cout << solve(W, H, w, h);
	return 0;
}

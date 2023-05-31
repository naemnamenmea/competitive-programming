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

int main() {
	const string _cur = "folding"; freopen((_cur + ".in").c_str(), "r", stdin); freopen((_cur + ".out").c_str(), "w", stdout);
	ld W, H, w, h, t, tt;
	cin >> W >> H >> w >> h;

	/*t = max(W, H);
	tt = min(W, H);
	H = t; W = tt;
	t = max(w, h);
	tt = min(w, h);
	h = t; w = tt;*/

	if (! (min(w, h) <= min(W, H) && max(w, h) <= max(W, H)) ) {
		cout << -1;
		return 0;
	}

	int i = 0;

	//cout << W << " " << H << " " << w << " " << h << " " << d(W, H, w, h) << endl;

	while (d(W, H, w, h) > 0) {

		if (W <= w || H <= w) {
			if (H <= w) {
				swap(W, H);
			}
		}

		else if (W <= h || H <= h) {
			if (W <= h) {
				swap(w, h);
			}
			else if (H <= h) {
				swap(W, H);
				swap(w, h);
			}
		}

		else {
			t = max(W, H);
			tt = min(W, H);
			H = t; W = tt;
			t = max(w, h);
			tt = min(w, h);
			h = tt; w = t;
		}

		h *= 2;
		i++;

		//cout << W << " " << H << " " << w << " " << h << " " << d(W, H, w, h) << endl;
	}
	cout << i;
	return 0;
}

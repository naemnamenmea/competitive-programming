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
	ll W, H, w, h, t, tt;
	cin >> W >> H >> w >> h;
	ll w2 = w, h2 = h;
	t = 0;
	if ((H<w&&H<h)||(W<w&&W<h))
	{
		cout << -1;
		return 0;
	}
	if ((h>W&&h>H) || (w > W&&w > H))
	{
		cout << -1;
		return 0;
	}
	if (!(min(w, h) <= min(W, H) && max(w, h) <= max(W, H))) {
		cout << -1;
		return 0;
	}
	bool canswap = true;
	if (w > W || h > H)
	{
		swap(w, h);
		canswap = false;
	}
	t = 0;
	while (w < W)
	{
		t++; w <<= 1;
	}
	while (h < H)
	{
		t++; h <<= 1;
	}
	if (canswap)
	{
		tt = 0;
		w = h2;
		h = w2;
		if (w > W || h > H)
		{
			cout << t;
			return 0;
		}
		while (w < W)
		{
			tt++; w <<= 1;
		}
		while (h < H)
		{
			tt++; h <<= 1;
		}
		cout << min(t, tt);
	}
	else
		cout << t;
	return 0;
}

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


int main() {
	const string _cur = "folding"; freopen((_cur + ".in").c_str(), "r", stdin); freopen((_cur + ".out").c_str(), "w", stdout);
	ll W, H, w, h;
	cin >> W >> H >> w >> h;
	if (W > H) {
		if (w < h) {
			swap(w, h);
		}
	}
	if (W < H) {
		if (w > h) {
			swap(w, h);
		}
	}
	if (w > W || h > H) {
		cout << -1;
		return 0;
	}
	//cout << W << " " << H << " " << w << " " << h << endl;
	int i = 0;
	while (W > w || H > h) {
		//ll minW = (W % 2 == 0) ? W / 2 : (W + 1) / 2;
		//ll minH = (H % 2 == 0) ? H / 2 : (H + 1) / 2;
		////cout << W << " " << H << " " << minW << " " << minH << " " << w << " " << h << endl;
		if (W > w) {
			w *= 2;
			i++;
			continue;
		}
		if (H > h) {
			h *= 2;
			i++;
			continue;
		}
	}
	cout << i;
	return 0;
}

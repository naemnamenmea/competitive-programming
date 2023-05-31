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


int main() {
	const string _cur = "king"; freopen((_cur + ".in").c_str(), "r", stdin); freopen((_cur + ".out").c_str(), "w", stdout);
	ll d, m, y, n, xd, xm, xy;
	cin >> d >> m >> y >> n;
	ll mini = -1, minid = -1, minim = -1, miniy = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> xd >> xm >> xy;
		if (y - xy > 18
			|| (y - xy == 18 && xm < m)
			|| (y - xy == 18 && xm == m && xd <= d)) {
			if (mini == -1) {
				mini = i;
				minid = xd;
				minim = xm;
				miniy = xy;
			}
			else if (xy > miniy 
				|| (xy == miniy && xm > minim) 
				|| (xy == miniy && xm == minim && xd > minid)) {
				mini = i;
				minid = xd;
				minim = xm;
				miniy = xy;
			}
		}
	}
	cout << mini;
	return 0;
}

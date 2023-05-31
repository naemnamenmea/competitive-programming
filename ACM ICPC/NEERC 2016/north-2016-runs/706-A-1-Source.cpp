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
	const string _cur = "anniversary"; freopen((_cur + ".in").c_str(), "r", stdin); freopen((_cur + ".out").c_str(), "w", stdout);
	ll w, h, ax, ay, bx, by;
	cin >> w >> h >> ax >> ay >> bx >> by;
	if (ax != bx) {
		cout << min(ax, bx) << " 0 " << max(ax, bx) << " " << h;
	}
	else if (ay != by) {
		cout << "0 " << min(ay, by) << " " << w << " " << max(ay, by);
	}
	return 0;
}

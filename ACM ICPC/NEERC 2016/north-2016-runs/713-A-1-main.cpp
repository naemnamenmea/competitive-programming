#include <bits/stdc++.h>



using ll = long long;
using ld = long double;

#define mp make_pair
#define pb push_back

#define filename "anniversary"

using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
	ll n,m,x1,y1,x2,y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2) {
		cout << 0 << " " << min(y1, y2) << " " << n << " " << max(y1, y2);
		return 0;
	}
	cout << min(x1, x2) << " " << 0 << " " << max(x1, x2) << " " << m;
	return 0;
}
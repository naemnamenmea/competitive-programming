#include <bits/stdc++.h>



using ll = long long;
using ld = long double;

#define mp make_pair
#define pb push_back

#define filename "folding"

using namespace std;

const ll inf = 1e9 + 10;

ll cnt(ll x, ll y) {
	if (x > y) {
		return inf;
	}
	ll cn = 0;
	while (x < y) {
		x += x;
		cn++;
	}
	return cn;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
	ll x,y,n,m;
	cin >> x >> y >> n >> m;
	ll a1 = cnt(n, x) + cnt(m, y);
	ll a2 = cnt(n, y) + cnt(m, x);
	if (a1 > a2) a1 = a2;
	if (a1 >=inf) {
		cout << -1;
	} else
	cout << a1;
	return 0;
}
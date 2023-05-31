#include <bits/stdc++.h>



using ll = long long;
using ld = long double;

#define mp make_pair
#define pb push_back

#define filename "king"

using namespace std;

const int MAXN = 1000;

struct ldate {
	int d, m, y, num;
};

bool comp(const ldate& d1, const ldate& d2) {
	return d1.y < d2.y || (d1.y == d2.y && d1.m < d2.m) || (d1.y == d2.y && d1.m == d2.m && d1.d < d2.d);
}
ldate a[MAXN]; 

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);

	int dk, mk, yk;
	cin >> dk >> mk >> yk;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, m, y;
		cin >> d >> m >> y;
		a[i].d = d;
		a[i].m = m;
		a[i].y = y;
		a[i].num = i + 1; 	
	}	
	sort(a, a + n, comp);
	for (int i = n - 1; i >= 0; i--) {
		if (yk - a[i].y > 18 || (yk - a[i].y == 18 && mk > a[i].m) || (yk - a[i].y == 18 && mk == a[i].m && dk >= a[i].d)) {
			cout << a[i].num;
			return 0;
		}
	}	
	cout << -1;		

	return 0;
}
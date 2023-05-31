#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 2e5;

int ans = 1<<30;

void check(int e, int r, int c, int v) {
	if ((e < c) || (r < v)) {
		return;
	}
	int t = 0;
	while (c < e) {
		c *= 2;
		t++;
	}
	while (v < r) {
		v *= 2;
		t++; 
	}
	ans = min(ans, t);
	
}

int main()
{
#ifdef KOBRA
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
#endif // KOBRA
	int q, w, e, r, t;
	cin >> q >> w >> e >> r;
	check(q, w, e, r);
	check(q, w, r, e);
	if (ans < 1<<30) {
		cout << ans;
	} else {
		cout << -1;
	}
    return 0;
}

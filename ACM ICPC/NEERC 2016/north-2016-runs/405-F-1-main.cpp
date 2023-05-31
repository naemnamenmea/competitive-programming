#include <bits/stdc++.h>

using namespace std;
                   
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int calc(long long a, long long b) {
	if (a > b) return (int)1e8;
	int res = 0;
	while (a < b) {
		a *= 2;
		res++;
	}
	return res;
}


int main () {                   
	freopen ("folding.in", "r", stdin);
	freopen ("folding.out", "w", stdout);
	int W, H, w, h;
	cin >> W >> H >> w >> h;

	int a = calc(h, H) + calc(w, W);
	a = min(a, calc(h, W) + calc(w, H));
	if (a > 1000000) {
		cout << -1 << endl;
	} else {
		cout << a << endl;
	}

	return 0;
}
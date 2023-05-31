#include <bits/stdc++.h>

using namespace std;

int get(int a, int b) {
	if (a == b) return 0;
	if (b + b >= a) return 1;
	return get((a + 1) / 2, b) + 1;
}

int solve(int n, int m, int x, int y) {
	if (n < x) return (int)2e9;
	if (m < y) return (int)2e9;
	return get(n, x) + get(m, y);
}

int main() {
    freopen("folding.in","r",stdin);
    freopen("folding.out","w",stdout);
    int w, h;
    int x, y;
    cin >> w >> h >> x >> y;
    int ans = solve(w, h, x, y);
    ans = min(ans, solve(w, h, y, x));
    if (ans == (int)2e9) ans = -1;
    cout << ans << endl;
	return 0;
}
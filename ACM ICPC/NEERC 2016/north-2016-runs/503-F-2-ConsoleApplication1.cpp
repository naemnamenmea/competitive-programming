#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	double W, H, w, h;
	int ans = 0;
	cin >> W >> H >> w >> h;
	int tmp = max(W, H);
	W = min(W, H);
	H = tmp;
	tmp = max(w, h);
	w = min(w, h);
	h = tmp;

	if (W < w || H < h) {
		cout << -1;
		return 0;
	}
	while (W > w) {
		ans++;
		W /= 2;
	}
	while (H > h) {
		ans++;
		H /= 2;
	}
	cout << ans;
	return 0;
}


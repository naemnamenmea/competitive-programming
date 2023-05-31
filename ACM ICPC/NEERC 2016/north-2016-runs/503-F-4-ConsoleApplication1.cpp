#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	double W, W1, H, H1, w, h;
	int ans = 0, ans1 = 0;
	cin >> W >> H >> w >> h;
	int tmp = max(W, H);
	W = min(W, H);
	H = tmp;
	H1 = W;
	W1 = H;
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

	if (W1 >= w && H1 >= h) {
		while (W1 > w) {
			ans1++;
			W1 /= 2;
		}
		while (H1 > h) {
			ans1++;
			H1 /= 2;
		}
	}
	if (ans1 == 0) ans1 = ans;

	cout << min(ans, ans1);
	return 0;
}


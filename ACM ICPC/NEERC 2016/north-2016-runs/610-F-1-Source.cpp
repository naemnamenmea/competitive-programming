#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	int W, H, w, h;
	int W1, H1, w1, h1;
	int k1 = 0, k2 = 0;
	cin >> W >> H;
	cin >> w >> h;
	if (W < H) swap(W, H);
	if (w < h) swap(w, h);
	if (W < w || H < h) {
		cout << "-1";
		return 0;
	}
	W1 = W; H1 = H;
	w1 = w; h1 = h;
	while (W1 > w1) {
		W1 = W1 / 2 + W1 % 2;
		k1++;
	}
	while (H1 > h1) {
		H1 = H1 / 2 + H1 % 2;
		k1++;
	}
	swap(w, h);
	W1 = W; H1 = H;
	w1 = w; h1 = h;
	while (W1 > w1) {
		W1 = W1 / 2 + W1 % 2;
		k2++;
	}
	while (H1 > h1) {
		H1 = H1 / 2 + H1 % 2;
		k2++;
	}
	cout << min(k1, k2);
	return 0;
}
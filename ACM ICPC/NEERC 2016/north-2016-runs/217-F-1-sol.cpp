#include <iostream>
#include <cstdio>

using namespace std;

const int INF = 2e9;

int main() {
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	int W, H, w, h, w1, h1, w2, h2;
	cin >> W >> H >> w >> h;
	w1 = w, h1 = h;
	w2 = h, h2 = w;
	int ans = INF;
	if (W >= w1 && H >= h1) {
		int tW = W, tH = H;
		int now = 0;
		while (tW > w1) {
			tW -= min(tW / 2, tW - w1);
			now++;
		}
		while (tH > h1) {
			tH -= min(tH / 2, tH - h1);
			now++;
		}
		ans = min(ans, now);
	}
	if (W >= w2 && H >= h2) {
		int tW = W, tH = H;
		int now = 0;
		while (tW > w2) {
			tW -= min(tW / 2, tW - w2);
			now++;
		}
		while (tH > h2) {
			tH -= min(tH / 2, tH - h2);
			now++;
		}
		ans = min(ans, now);
	}
	cout << (ans == INF ? -1 : ans) << endl;
	return 0;
}
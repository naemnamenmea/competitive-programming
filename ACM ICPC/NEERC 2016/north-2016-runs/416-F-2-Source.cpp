#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c, d, W, H, w, h;
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	cin >> a >> b >> c >> d;
	int st1 = 0, st2 = 0;
	int st3 = 0, st4 = 0;
	bool solved = false;
	W = a, H = b, w = c, h = d;
	if (w <= W && h <= H)
	{
		solved = true;
	}
	while (w < W)
	{
		W = W/2+W%2;
		st1++;
	}
	while (h < H)
	{
		H = H/2+H%2;
		st2++;
	}
	W = b, H = a, w = c, h = d;
	int ans = st1 + st2;
	if (!solved) {
		ans = -1;
	}
	solved = false;
	st1 = 0;
	st2 = 0;
	if (w <= W && h <= H)
	{
		solved = true;
	}
	while (w < W)
	{
		W = W / 2 + W % 2;
		st1++;
	}
	while (h < H)
	{
		H = H / 2 + H % 2;
		st2++;
	}
	if (solved) {
		if (ans == -1)
			ans = st1 + st2;
		ans = min(ans, st1+st2);
	}
	cout << ans;
	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int W, H, w, h;
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	cin >> W >> H >> w >> h;
	if (W > H)
		swap(W, H);
	if (w > h)
		swap(w, h);
	int st1 = 0, st2 = 0;
	if (w > W || h > H)
	{
		cout << -1;
		return 0;
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
	cout << st1 + st2;
	return 0;
}

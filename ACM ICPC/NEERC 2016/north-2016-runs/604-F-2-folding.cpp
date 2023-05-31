#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

//#define Debug

int main()
{
#ifdef Debug
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
#endif

	int W, H, w, h;

	cin >> W >> H >> w >> h;

	if (w > W || h > H)
	{
		swap(W, H);
		if (w > W || h > H) {
			cout << -1 << endl;
			return 0;
		}

	}

	int f = 0;
		while (w < W / 2)
		{
			W = W -  W / 2;
			f++;
		}

		if (W != w && w >= W / 2)
			f++;
		
		while (h < H / 2)
		{
			H = H - H / 2;
			f++;
		}

		if (h != H && h >= H / 2)
			f++;

		cout << f << endl;

  return 0;
}
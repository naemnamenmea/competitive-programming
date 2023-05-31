#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>

typedef long long ll;
using namespace std;

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	int W, H, w, h;
	cin >> W >> H >> w >> h;
	if ((w > W && h < H) || (w < W && h > H))
	{
		swap(w, h);
	}
	if (w > W || h > H)
	{
		cout << -1;
		return 0;
	}
	int res1 = 0, res2 = 0;
	int tw = w, th = h;
	while (W > tw)
	{
		tw <<= 1;
		res1++;
	}
	while (H > th)
	{
		th <<= 1;
		res1++;
	}

	while (W > h)
	{
		h <<= 1;
		res2++;
	}
	while (H > w)
	{
		w <<= 1;
		res2++;
	}
	cout << min(res1, res2);
	return 0;
}
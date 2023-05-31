#include <bits/stdc++.h>
using namespace std;

int kd, km, ky;

int is18(int d, int m, int y)
{
	//cout << d << " " << m << " " << y << endl;
	if (ky - y > 18)
		return 1;
	if (ky - y == 18 && km > m)
		return 1;
	if (ky - y == 18 && km == m && kd >= d)
		return 1;
	return 0;
}

int main()
{
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	cin >> kd >> km >> ky;
	int n;
	cin >> n;

	int mind = 1, minm = 1, miny = 1, ans = -1;
	for (int i = 0; i < n; i++)
	{
		int di, mi, yi;
		cin >> di >> mi >> yi;

		//cout << is18(di, mi, yi) << endl;
		if (is18(di, mi, yi) && (yi > miny || (yi == miny && mi > minm) || (yi == miny && mi == minm && di >= mind)))
		{
			mind = di;
			minm = mi;
			miny = yi;
			ans = i + 1;
		}
	}

	cout << ans;
	return 0;
}
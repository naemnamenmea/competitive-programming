#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int w, h, ax, ay, bx, by;
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	cin >> w >> h >> ax >> ay >> bx >> by;
	if (ax != bx)
		cout << min(ax, bx) << ' ' << 0 << ' ' << min(ax, bx) + 1 << ' ' << h;
	else
		cout << 0 << ' ' << min(ay, by) << ' ' << w << ' ' << min(ay, by) + 1;
	return 0;
}

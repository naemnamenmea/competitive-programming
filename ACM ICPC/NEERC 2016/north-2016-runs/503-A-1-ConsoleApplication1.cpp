#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	int w, h, ax, ay, bx, by, cx, cy, dx, dy;
	cin >> w >> h >> ax >> ay >> bx >> by;
	cy = 0;
	dy = h;
	cx = min(ax, bx);
	dx = max(ax, bx);
	cout << cx << " " << cy << " " << dx << "  " << dy;
	return 0;
}


#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	int w, h, ax, ay, bx, by, cx, cy, dx, dy;
	cin >> w >> h >> ax >> ay >> bx >> by;
	if (ax != bx && ay % h != 0 && by % h != 0) {
		cy = 0;
		dy = h;
		cx = min(ax, bx);
		dx = max(ax, bx);
	}
	else if (ax != bx && (ay % h == 0 || by % h == 0)) {
		if (ay == by) {
			cy = 0;
			dy = h;
			cx = dx = (ax + bx) / 2;
		}
		else {
			if (ax < bx) {
				cy = abs(h - ay);
				dy = abs(h - by);
				cx = ax;
				dx = bx;
			}
			else {
				cy = abs(h - by);
				dy = abs(h - ay);
				cx = bx;
				dx = ax;
			}
		}
	}
	else if (ax == bx) {
		if (abs(ay - by) > 1) {
			cx = 0;
			dx = w;
			cy = dy = (ay + by) / 2;
		}
		else {
			cx = 0;
			dx = w;
			cy = ay;
			dy = by;
		}
	}
	cout << cx << " " << cy << " " << dx << " " << dy;
	return 0;
}


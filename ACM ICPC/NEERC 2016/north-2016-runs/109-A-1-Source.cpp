#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	int w, h, ax, ay, bx, by;
	cin >> w >> h >> ax >> ay >> bx >> by;
	if (abs(ax - bx) >= 2)
		cout << (ax + bx) / 2 << " 0 " << (ax + bx) / 2 << ' ' << h;
	else if (abs(ay - by) >= 2)
		cout << "0 " << (ay + by) / 2 << ' ' << w << ' ' << (ay + by) / 2;
	else if (abs(ax - bx) == 1)
		cout << ax << " 0 " << bx << ' ' << h;
	else
		cout << "0 " << ay << ' ' << w << ' ' << by;
	return 0;
}
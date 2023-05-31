#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>

using namespace std;
void main()
{
	ifstream in("anniversary.in");
	ofstream out("anniversary.out");
	int w, h, ax, bx, ay, by;
	in >> w >> h >> ax >> ay >> bx >> by;
	if (abs(ax - bx) > 1)
	{
		int x;
		if (ax > bx) x = bx + 1; else x = ax + 1;
		out << x << " " << "0 " << x << " " << h;
		return;
	}
	if (abs(ay - by) > 1)
	{
		int y;
		if (ay > by) y = by + 1; else y = ay + 1;
		out << "0 " << y <<" " << w << " " << y;
		return;
	}
	if (abs(ay - by) == 1 && abs(ax - bx)==1)
	{
		int x, y, x1, y1;

		x = bx; y = ay;
		x1 = ax; y1 = by;
		out << x << " " << y << " " << x1 << " " << y1;
		return;
	}
	if (ay == by)
	{
		out << ax << " 0 " << bx << " " << h;
		return;
	}
	if (ax == bx)
	{
		out << "0 " << ay <<" "<< w << " " << by;
		return;
	}
}
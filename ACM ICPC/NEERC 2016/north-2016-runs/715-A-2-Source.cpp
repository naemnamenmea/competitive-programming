#include <fstream>
#include <math.h>

using namespace std;

int main()
{
	ifstream fin("anniversary.in");
	ofstream fout("anniversary.out");

	int sx, sy, ex, ey;
	int w, h, ax, ay, bx, by;
	fin >> w >> h >> ax >> ay >> bx >> by;

	if (ax == bx && abs(ay - by) > 1 && ay < by) {
		sy = ay + 1;
		sx = 0;
		ey = ay + 1;
		ex = w;
	}
	else if (ay == by && abs(ax - bx) > 1 && ax < bx) {
		sx = ax + 1;
		sy = 0;
		ex = ax + 1;
		ey = h;
	}
	else if (ax == bx && abs(ay - by) > 1 && ay > by) {
		sy = ay - 1;
		sx = 0;
		ey = ay - 1;
		ex = w;
	}
	else if (ay == by && abs(ax - bx) > 1 && ax > bx) {
		sx = ax - 1;
		sy = 0;
		ex = ax - 1;
		ey = h;
	}
	else if (ax == bx && abs(ay - by) == 1) {
		sx = 0;
		sy = ay;
		ex = w;
		ey = by;
	}
	else if (ay <= by && bx <= ax) {
		sx = bx;
		sy = 0;
		ex = ax;
		ey = h;
	}
	else if (ay >= by && bx >= ax) {
		sx = ax;
		sy = 0;
		ex = bx;
		ey = h;
	}
	else if (ay <= by && bx >= ax) {
		sx = ax;
		sy = h;
		ex = bx;
		ey = 0;
	}
	else if (ay >= by && bx <= ax) {
		sx = bx;
		sy = h;
		ex = ax;
		ey = 0;
	}

	fout << sx << " " << sy << " " << ex << " " << ey;
	return 0;
}
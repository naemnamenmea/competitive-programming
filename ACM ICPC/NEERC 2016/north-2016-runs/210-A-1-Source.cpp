#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	ifstream in("anniversary.in");
	ofstream out("anniversary.out");
	long long w, h, ax, ay, bx, by;
	long long resx1, resy1, resx2, resy2;

	in >> w >> h >> ax >> ay >> bx >> by;

	if (ax == bx)
	{
		resx1 = 0;
		resy1 = ay;

		resx2 = w;
		resy2 = by;
	}
	else
	{
		resx1 = ax;
		resy1 = 0;

		resx2 = bx;
		resy2 = h;

	}
	out << resx1 << " " << resy1 << " " << resx2 << " " << resy2;

	return 0;
}

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

struct mymm{
	long long x, y;
};

		
	ifstream in("anniversary.in");
	ofstream out("anniversary.out");

	int main(){

		long long w, h;
		
		mymm a, b;
		in >> w >> h >> a.x >> a.y >> b.x >> b.y;
		if ((a.y == b.y) || (a.x != b.x&&a.y != b.y))
			out << a.x << " " << 0 << " " << b.x << " " << h;
		else out << 0 << " " << a.y << " " << w << " " << b.y;

		return 0;
	}



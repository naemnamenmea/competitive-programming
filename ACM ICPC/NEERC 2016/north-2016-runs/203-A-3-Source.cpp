#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	string name = "anniversary";
	ifstream in(name + ".in");
	ofstream out(name + ".out");

	long long w, h, ax, ay, bx, by;
	in >> w >> h >> ax >> ay >> bx >> by;

	if (abs(ax - bx) >= 2) {
		out << min(ax, bx) + 1 << " 0 " << min(ax, bx) + 1 << " " << h;
	}
	else if (abs(ay - by) >= 2) {
		out << "0 " << min(ay,by) + 1 << h << " " << w << " " << ax + 1;
	}
	else {
		if (ax == bx) {
			out << "0 " << ay << " " << w << " " << by;
		}
		else {
			out << min(ax, bx) << " 0 " << max(ax, bx) << " " << h;
		}
	}


	return 0;
}
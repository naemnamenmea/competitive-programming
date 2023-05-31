#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ifstream in("anniversary.in");
	ofstream out("anniversary.out");
	int w, h;
	int c1x, c1y, c2x, c2y, X1, X2;
	in >> w >> h >> c1x >> c1y >> c2x >> c2y;
	if (c1x == c2x) {
		X1 = c1y;
		X2 = c2y;
		out << "0 " << X1 << " " << w << " " << X2;
		return 0;
	};
	X1 = max(c1x, c2x);
	X2 = min(c1x, c2x);
	out << X1 << " 0 " << X2 << ' ' << h;
	return 0;
}
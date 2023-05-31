#include <fstream>

using namespace std;

int main() {
	ifstream in("anniversary.in");
	ofstream out("anniversary.out");
	int w, h, x1, x2, y1, y2;
	in >> w >> h >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2) {
		out << "0 " << y1 << " " << w << " " << y2;
	}
	else {
		out << x1 << " 0 " << x2 << " " << h;
	}
	return 0;
}
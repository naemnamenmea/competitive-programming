#include <fstream>

using namespace std;
int main(){

	long long w, h, ax, ay,c1x,c1y,c2x,c2y, bx, by;
	ifstream in("anniversary.in");
	ofstream out("anniversary.out");
	in >> w >> h >> c1x >> c1y >> c2x >> c2y;
	if (c1x == c2x)out << "0 " << c1y << " " << w<< " "<<c2y;
	else out << c1x << " 0 " << c2x << " " << h;


	return 0;
}
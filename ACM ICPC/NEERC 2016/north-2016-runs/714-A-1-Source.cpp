#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	long long int w, h, x1, x2, y1, y2;
	ifstream in("anniversary.in");
	ofstream out("anniversary.out");

	in >> w >> h >> x1 >> y1 >> x2 >> y2;

	if (x1 != x2)
		out << x1 << " " << 0 << " " << x2 << " " << h;
	else 
		out << 0 << " " << y1 << " " << w << " " << y2;

	return 0;
}

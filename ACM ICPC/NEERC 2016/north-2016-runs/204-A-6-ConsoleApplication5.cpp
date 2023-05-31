// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <math.h>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("anniversary.in");
	out.open("anniversary.out");
	int w, h, ax, ay, bx, by;
	in >> w >> h >> ax >> ay >> bx >> by;
	
    int dx = bx - ax;
	int dy = by - ay;
	if ((ay == by)||(dy>=dx)) {
		out<<ax<<" "<<0<<" "<<bx<<" "<<h;
		return 0;
	}
	if ((ax == bx)||(dx>=dy)){
		out << ax << " " << 0 << " " << by << " " << h;
	}

	in.close();
	out.close();
	return 0;
}
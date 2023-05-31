#include <fstream>

using namespace std;

int main() {
	
	ifstream fin;
	fin.open("anniversary.in");
	long h, w, ax, bx, ay, by;
	fin >> w >> h >> ax >> ay >> bx >> by;
	fin.close();

	ofstream fout;
	fout.open("anniversary.out");
	if (ay == by) fout << ax << " " << 0 << " " << bx << " " << h;
	else fout << 0 << " " << ay << " " << w << " " << by;

	return 0'

}
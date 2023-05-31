#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	ifstream in("anniversary.in");
	ofstream out("anniversary.out");
	long long h, w, ax, bx, ay, by;
	in >> w >> h >> ax >> ay >> bx >> by;
	if (ax == bx) out << 0 << " " << ay << " " << w << " "<<by;
	else out << ax << " " << 0 << " " << bx << " " << h;
	in.close();
	out.close();
	return 0;
}


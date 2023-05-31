#include <fstream>

using namespace std;

int main(){

	ifstream cin("anniversary.in");
	ofstream cout("anniversary.out");

	int w, h, ax, ay, bx, by;

	cin >> w >> h >> ax >> ay >> bx >> by;

	if (ax == bx)
		cout << "0 " << ay << " " << w << ' ' << by;
	else
		cout << ax << " 0 " << bx << ' ' << h;
	cout << '\n';
	return 0;
}
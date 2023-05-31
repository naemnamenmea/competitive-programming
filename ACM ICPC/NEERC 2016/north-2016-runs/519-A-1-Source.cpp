#include<fstream>

using namespace std;

int main() {
	ifstream cin("anniversary.in");
	ofstream cout("anniversary.out");
	int w, h, x1, y1, x2, y2;
	cin >> w >> h >> x1 >> y1 >> x2 >> y2;
	if (x1 != x2)
		cout << x1 << ' ' << h << ' ' << x2 << ' ' << 0 << endl;
	else
		cout << w << ' ' << y1 << ' ' << 0 << ' ' << y2 << endl;
	system("pause");
	return 0;
}
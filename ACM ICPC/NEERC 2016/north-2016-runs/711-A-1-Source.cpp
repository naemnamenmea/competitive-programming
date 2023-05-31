#include<iostream>
#include<math.h>

using namespace std;

const double eps = 1e-9;



int main()
{
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	long long w, h, x1, x2, y1, y2,ax,ay;
	double ang1, ang2, ang3;
	cin >> w >> h >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2)
		cout << "0 " << y1 << " " << w << " " << y2;
	else
		cout << x1 << " 0 " << x2 << " " << h;

	return 0;
}
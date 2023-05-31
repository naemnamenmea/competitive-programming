#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int 
		x1,
		y1,
		w,
		h,
		x2,
		y2;

	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);

	cin >> w >> h;
	cin >> x1 >> y1 >> x2 >> y2;

	if (x1 == x2)
	{
		cout << 0 << " " << y1 << " " << w << " " << y2;
	}
	else
	{
		cout << x1 << " " << 0 << " " << x2 << " " << h;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
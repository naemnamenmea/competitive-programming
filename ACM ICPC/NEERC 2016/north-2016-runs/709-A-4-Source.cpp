#include "iostream"
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;



int main()

{
		freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);

	long long w, h, ax, ay, bx, by;
	cin >> w >> h >> ax >> ay >> bx >> by;
	
	if (abs(ax - bx) >= 2)
	{
		if (ax < bx)
		{
			cout << ax + 1 << " " << "0" << " " << ax + 1 << " " << h;
		}
		else
		{
			cout << bx + 1 << " " << "0" << " " << bx + 1 << " " << h;
		}
	}
	else
	{
		if (abs(ay - by) >= 2)
		{
			if (ay < by)
			{
				cout << "0" << " " << by - 1 << " " << w << " " << by - 1;
			}
			else
			{
				cout << "0" << " " << ay - 1 << " " << w << " " << ay - 1;
			}

		}
		
		else
		{
			if (ax != bx && ay == by)
			{
				cout << ax << " " << "0" << " " << bx << " " << h;
			}
			if (ax == bx && ay != by)
			{
				cout << "0" << " " << by << " " << w << " " << ay;
			}
		}
	}



	//system("pause");
	return 0;
}
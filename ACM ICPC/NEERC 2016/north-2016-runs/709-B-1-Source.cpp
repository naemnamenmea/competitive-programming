#include "iostream"
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()

{
	freopen("boysgirls.in", "r", stdin);
	freopen("boysgirls.out", "w", stdout);
	int n, x, y;
	int ch;
	cin >> n >> x >> y;
	if (x + y - 2 < n)
	{
		cout << "Impossible";
	}
	else
	{
		int	i = 0; x--; y--;
		while (i < n)
		{
			if (x > 0)
			{
				cout << "B"; x--; i++;
			}
			if (i < n  && y>0)
			{
				cout << "G"; y--; i++;
			}
		}


	}
	
	//system("pause");
	return 0;
}
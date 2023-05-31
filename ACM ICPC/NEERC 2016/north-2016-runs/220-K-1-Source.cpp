#include<stdio.h>
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	
	int Y, M, D;
	int y, m, d;
	int number;
	y = 0;
	m = 0;
	d = 0;
	int mas[105][3] = {};
	cin >> D >> M >> Y;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> mas[i][0] >> mas[i][1] >> mas[i][2];
		if ((Y - mas[i][2] > 18)
			|| ((Y - mas[i][2] == 18) && (mas[i][1] < M))
			|| ((Y - mas[i][2] == 18) && (mas[i][1] == M) && (mas[i][0] <= D)))
		{
			if (mas[i][2] > y)
			{
				y = mas[i][2];
				d = mas[i][0];
				m = mas[i][1];
				number = i + 1;
				continue;
			}
			if (mas[i][2] == y)
			{
				if (mas[i][1] > m)
				{
					y = mas[i][2];
					d = mas[i][0];
					m = mas[i][1];
					number = i + 1;
					continue;
				}
				if (mas[i][1] == m)
				{
					if (mas[i][0] > d)
					{
						y = mas[i][2];
						d = mas[i][0];
						m = mas[i][1];
						number = i + 1;
						continue;
					}

				}
			}

		}
	}
if (y == 0)
{
	cout << "-1";
}
else
{
	cout << number;
}
return 0;
}
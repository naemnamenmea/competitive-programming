#include<fstream>
#include <algorithm>

using namespace std;

int toNum(int day, int mounth, int year)
{
	return day + 100 * mounth + 10000 * year;
}

/*
22 10 2016
7
28 2 1999
22 7 1995
21 10 1998
23 10 1998
3 9 2000
1 4 2013
17 12 2004*/

int main() {
	ifstream cin("king.in");
	ofstream cout("king.out");

	int d, m, y; cin >> d >> m >> y;
	int king = toNum(d, m, y);
	int n; cin >> n;
	int Max = -1;
	int MaxId = -1;
	int target;
	for (int i = 1; i <= n; i++)
	{
		cin >> d >> m >> y;
		target = toNum(d, m, y);
		if ((king - target) >= 180000)
		{
			if (Max == -1 || target > Max)
			{
				Max = target;
				MaxId = i;
			}
		}
	}
	cout << MaxId << endl;

	//system("pause");
	return 0;
}
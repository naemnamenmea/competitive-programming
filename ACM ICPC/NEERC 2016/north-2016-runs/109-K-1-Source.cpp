#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct son {
	int day, month, year, number;
	bool check;
	bool operator< (const son &X) const
	{
		if (year > X.year)
		{
			return true;
		}
		if (year != X.year)
		{
			return false;
		}
		if (month > X.month)
		{
			return true;
		}
		if (month != X.month)
		{
			return false;
		}
		return (day > X.day);
	}
};


int main()
{
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);

	int day, month, year, n;
	scanf("%d %d %d %d", &day, &month, &year, &n);
	vector <son> sons(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &sons[i].day, &sons[i].month, &sons[i].year);
		sons[i].number = i + 1;
		sons[i].check =
			(year - sons[i].year > 18 ||
			(year - sons[i].year == 18
			&& (month > sons[i].month
			|| (month == sons[i].month && day >= sons[i].day))));
	}
	sort(sons.begin(), sons.end());
	for (auto s : sons)
	{
		if (s.check)
		{
			printf("%d", s.number);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	int a[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int day_b, mounth_b, year_b, n, i;
	int days_b, days;
	int day, mounth, year;
	int mini=-1, min_val=1000000000;
	cin >> day_b >> mounth_b >> year_b;
	days_b = 365 * (year_b - 1) + a[mounth_b - 1] + day_b;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> day >> mounth >> year;
		days = 365 * (year - 1) + a[mounth - 1] + day;
		if (days_b - days >= 365 * 18 && days_b - days - 18 * 365 < min_val) {
			min_val = days_b - days - 18 * 365;
			mini = i;
		}
	}
	cout << mini;
	return 0;
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
17 12 2004
*/
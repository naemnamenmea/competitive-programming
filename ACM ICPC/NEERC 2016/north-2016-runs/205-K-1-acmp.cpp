#include<iostream>
#include <algorithm>
using namespace std;

struct date {
	int year;
	int month;
	int day;
};

bool Less(date a, date b) {
	if (a.year<b.year) return true;
	else if (a.year == b.year) {
		if (a.month<b.month) return true;
		else if (a.month == b.month) {
			if (a.day<b.day) return true;
		}
	}
	return false;
}

bool Equal(date a, date b) {
	if (!Less(a, b) && !Less(b, a)) return true;
	return false;
}

bool More(date a, date b) {
	if (!Less(a, b) && !Equal(b, a)) return true;
	return false;
}

bool less_or_equal(date a, date b) {
	if (Less(a, b) || Equal(a, b)) return true;
	return false;
}

date make_date(int day, int month, int year) {
	date temp;
	temp.day = day;
	temp.month = month;
	temp.year = year;
	return temp;
}

int main()
{
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	int d, m, y;
	cin >> d >> m >> y;
	date border = make_date(d, m, y - 18);
	int n;
	cin >> n;
	date Min = make_date(1, 1, -10000);
	date Date;
	int MinIndex=-1;
	for (int i = 1; i <= n; i++) {
		cin >> d >> m >> y;
		Date = make_date(d, m, y);
		if (less_or_equal(Date, border) && More(Date, Min)) {
			Min = make_date(Date.day, Date.month, Date.year);
			MinIndex = i;
		}
	}
	cout << MinIndex;
}

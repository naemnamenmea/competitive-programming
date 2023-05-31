//============================================================================
// Name        : k.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int year_days = 365;
int days_in_18 = 365 * 18;

int main() {
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	int d, m, y;
	scanf("%d %d %d", &d, &m, &y);
	int king_day = 0;
	for (int j = 0; j < m - 1; j++) {
		king_day += month[j];
	}
	king_day += d;
	int n;
	scanf("%d", &n);
	int count = 0;
	int king = -1;
	int d2, m2, y2 = 20000;
	int new_king_day = 20000 * 365;
	for (int i = 0; i < n; i++) {
		int d1, m1, y1;
		scanf("%d %d %d", &d1, &m1, &y1);
		int cur_day = 0;
		for (int j = 0; j < m1 - 1; j++) {
			cur_day += month[j];
		}
		cur_day += d1;

		int full_day = (y - y1) * 365 + (king_day - cur_day);
//		if (cur_day > king_day) {
//			continue;
//		}
//		printf("cur_day: %d king_day: %d full_day: %d new: %d\n", cur_day, king_day, full_day, new_king_day);
		if ((full_day >= days_in_18) && (full_day < new_king_day)) {
			new_king_day = full_day;
			king = i + 1;
		}
	}
//	for (int i = 0; i < n; i++) {
//		int d1, m1, y1;
//		scanf("%d %d %d", &d1, &m1, &y1);
//		if ((y - y1) < 18)
//			continue;
//		if ((y - y1) > 18)
//		{
//			count++;
//			continue;
//		}
//		int cur_day = 0;
//		for (int j = 0; j < m1 - 1; j++) {
//			cur_day += month[j];
//		}
//		cur_day += d1;
//		if (king_day >= cur_day)
//			count++;
//		if () {
//			new_king_day
//		}
//	}
	printf("%d", king);
	return 0;
}

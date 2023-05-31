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
	king_day++;
	int n;
	scanf("%d", &n);
	int count = 0;
	for (int i = 0; i < n; i++) {
		int d1, m1, y1;
		scanf("%d %d %d", &d1, &m1, &y1);
		if ((y - y1) < 18)
			continue;
		if ((y - y1) > 18)
		{
			count++;
			continue;
		}
		int cur_day = 0;
		for (int j = 0; j < m1 - 1; j++) {
			cur_day += month[j];
		}
		cur_day += d1;
		if (king_day >= cur_day)
			count++;
	}
	printf("%d", (count? count: -1));
	return 0;
}

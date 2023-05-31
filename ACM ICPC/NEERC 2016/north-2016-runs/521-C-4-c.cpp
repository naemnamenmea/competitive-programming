//============================================================================
// Name        : c.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;

int c[100005][2];
int a[100005];

//vector<int> f;
//vector<int> s;

int main() {
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c[i][0], &c[i][1]);
	}
	int count = 0;
	int max_seq = 0;
	for (int i = 0; i < n; i++) {
		count = 0;
		max_seq = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			int eq;
			if (j + 1 == i) {
				if (j + 2 > n)
					eq = -1;
				else
					eq = c[j + 2][0];
			} else {
				eq = c[j + 1][0];
			}
			if ((c[i][0] > c[j][0]) && (c[j][0] > eq) && !(j + 1 > n)) {
				count++;
			} else if (j + 1 > n) {
				if (c[i][0] > c[j][0])
					count++;
			} else {
				if (c[i][0] > c[j][0]) {
					count++;
				}
				max_seq = max(count, max_seq);
				count = 0;
				break;
			}
		}
		max_seq = max(count, max_seq);
		a[i] = max_seq;
		count = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			int eq;
			if (j + 1 == i) {
				if (j + 2 > n)
					eq = -1;
				else
					eq = c[j + 2][1];
			} else {
				eq = c[j + 1][1];
			}
			if ((c[i][1] > c[j][1]) && (c[j][1] > eq) && !(j + 1 > n)) {
				count++;
			} else if (j + 1 > n) {
				if (c[i][1] > c[j][1])
					count++;
			} else {
				if (c[i][1] > c[j][1]) {
					count++;
				}
				max_seq = max(count, max_seq);
				count = 0;
				break;
			}
		}
		max_seq = max(count, max_seq);
		a[i] = max(max_seq, a[i]);
	}
	max_seq = 0;
	count = 0;
	for (int i = n - 1; i >= 0; i--) {
		count = 0;
		max_seq = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (i == j)
				continue;
			int eq;
			if (j - 1 == i) {
				if (j - 2 < 0)
					eq = -1;
				else
					eq = c[j - 2][0];
			} else {
				eq = c[j - 1][0];
			}
			if ((c[i][0] > c[j][0]) && (c[j][0] > eq) && !(j - 1 < 0)) {
				count++;
			} else if (j - 1 < 0) {
				if (c[i][0] > c[j][0])
					count++;
			} else {
				if (c[i][0] > c[j][0]) {
					count++;
				}
				max_seq = max(count, max_seq);
				count = 0;
				break;
			}
		}
		max_seq = max(count, max_seq);
		a[i] = max(max_seq, a[i]);
		count = 0;
		max_seq = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (i == j)
				continue;
			int eq;
			if (j - 1 == i) {
				if (j - 2 < 0)
					eq = -1;
				else
					eq = c[j - 2][1];
			} else {
				eq = c[j - 1][1];
			}
			if ((c[i][1] > c[j][1]) && (c[j][1] > eq) && !(j - 1 < 0)) {
				count++;
			} else if (j - 1 < 0) {
				if (c[i][1] > c[j][1])
					count++;
			} else {
				if (c[i][1] > c[j][1]) {
					count++;
				}
				max_seq = max(count, max_seq);
				count = 0;
				break;
			}
		}
		max_seq = max(count, max_seq);
		a[i] = max(max_seq, a[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}

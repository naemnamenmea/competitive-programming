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

int a[100005][2];
int c[100005];

int main() {
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i][0], &a[i][1]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if ((a[i][0] > a[j][0]) || (a[i][1] > a[j][1]))
				c[i]++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", c[i]);
	}
	return 0;
}

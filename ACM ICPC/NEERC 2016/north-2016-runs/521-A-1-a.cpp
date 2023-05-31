//============================================================================
// Name        : a.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	int w, h, ax, ay, bx, by;
	scanf("%d %d %d %d %d %d", &w, &h, &ax, &ay, &bx, &by);
	if (ax == bx) {
		printf("%d %d %d %d", 0, ay, w, by);
	} else {
		printf("%d %d %d %d", ax, 0, bx, h);
	}
	return 0;
}

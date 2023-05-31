//============================================================================
// Name        : f.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	int w, h;
	int w1, h1;
	scanf("%d %d", &w, &h);
	scanf("%d %d", &w1, &h1);
	int w2 = w, h2 = h;
	w = max(w2, h2);
	h = min(w2, h2);
	w2 = w1;
	h2 = h1;
	w1 = max(w2, h2);
	h1 = min(w2, h2);

	if (((w1 > w) && (w1 > h)) || ((h < w1) && (h < h1))) {
		printf("-1");
		return 0;
	}

	int count = 0;
	while ((w / w1) > 2) {
		w /= 2;
		count++;
	}

	if (w != w1) {
		count++;
	}

	while ((h / h1) > 2) {
		h /= 2;
		count++;
	}

	if (h != h1) {
		count++;
	}

	printf("%d", count);

	return 0;
}

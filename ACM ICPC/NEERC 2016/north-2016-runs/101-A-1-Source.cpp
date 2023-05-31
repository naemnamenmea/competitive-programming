#include <iostream>
#include <cstdio>
#include <cmath>

//#define LOCAL_BUILD 
#define zadacha "anniversary"

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

#ifdef LOCAL_BUILD
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(zadacha".in", "r", stdin);
	freopen(zadacha".out", "w", stdout);
#endif

	int w, h;
	
	cin >> w >> h;

	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;

	int sx, sy, ex, ey;

	if (ax == bx) {
		sx = 0; ex = w;
		sy = ay; ey = by;
	} else {
		sx = ax; ex = bx;
		sy = 0; ey = h;
	}

	cout << sx << " " << sy << " " << ex << " " << ey << endl;

	return 0;
}

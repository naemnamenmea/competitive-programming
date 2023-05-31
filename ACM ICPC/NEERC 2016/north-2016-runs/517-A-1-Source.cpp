#define _CRT_SEURE_NO_WARNINGS
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>

using namespace std;

int main(){
	freopen("anniversary.in", "rt", stdin);
	freopen("anniversary.out", "wt", stdout);
	int w, h, ax, ay, bx, by;
	scanf("%d%d %d%d %d%d", &w, &h, &ax, &ay, &bx, &by);
	int sx, sy, ex, ey;
	if (ax == bx){
		sx = 0;
		sy = ay;
		ex = w;
		ey = by;
	}
	else if (ay == by){
		sx = ax;
		sy = 0;
		ex = bx;
		ey = h;
	}
	else {
		sx = ax;
		ex = bx;
		if (by > ay){
			sy = h;
			ey = 0;
		}
		else{
			sy = 0;
			ey = h;
		}
	}
	printf("%d %d %d %d", sx, sy, ex, ey);
	return 0;
}
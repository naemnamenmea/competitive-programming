#define _CRT_SEURE_NO_WARNINGS
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>

using namespace std;

int main(){
	freopen("king.in", "rt", stdin);
	freopen("king.out", "wt", stdout);
	int mt[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int dk, yk;
	int d, m, y;
	scanf("%d%d%d", &d, &m, &y);
	yk = y;
	dk = d + mt[m - 1];
	int n;
	scanf("%d", &n);
	int df, yf;
	int da = -1, ya = -1, na = -2;
	for (int i = 0; i < n; ++i){
		scanf("%d%d%d", &d, &m, &y);
		yf = y;
		df = d + mt[m - 1];
		if (yk - yf < 18) continue;
		if (yk - yf == 18 && dk < df) continue;
		if (yf > ya || yf == ya && df > da){
			ya = yf;
			da = df;
			na = i;
		}
	}
	printf("%d", na + 1);
	return 0;
}
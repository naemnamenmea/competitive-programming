#define _CRT_SEURE_NO_WARNINGS
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>

using namespace std;

int check(long long a, long long A){
	int k = 0;
	while (A > a){
		++k;
		a <<= 1;
	}
	return k;
}

int main(){
	freopen("folding.in", "rt", stdin);
	freopen("folding.out", "wt", stdout);
	int w, h, W, H;
	scanf("%d%d%d%d", &W, &H, &w, &h);
	if ((w > W && w > H) || (h > W && h > H)){
		printf("-1");
		return 0;
	}
	int a, b, a2, b2;
	a = check(w, W);
	b = check(h, H);
	a2 = check(h, W);
	b2 = check(w, H);
	if (a + b < a2 + b2)
		printf("%d", a + b);
	else
		printf("%d", a2 + b2);
	return 0;
}
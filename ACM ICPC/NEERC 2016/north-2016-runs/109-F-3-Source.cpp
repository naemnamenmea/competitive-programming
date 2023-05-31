#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX(lhs,rhs) (lhs>rhs?lhs:rhs)
#define MIN(lhs,rhs) (lhs>rhs?rhs:lhs)
#define INF 1000000000
using namespace std;
int main()
{
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	int W, H, w, h;
	cin >> W >> H >> w >> h;
	int a = (int)ceil(log2((double)W / w)),
		b = (int)ceil(log2((double)H / h)),
		c = (int)ceil(log2((double)W / h)),
		d = (int)ceil(log2((double)H / w));
	int f1 = ((a >= 0 && b >= 0) ? a + b : INF),
			f2 = ((c >= 0 && d >= 0) ? c + d : INF);
	if (((MIN(w, h) <= MIN(W, H)) && (MAX(w, h) <= MAX(W, H))) && (f1 != INF || f2 != INF))
		cout << MIN(f1, f2);
	else
	{
		cout << -1;
	}
	return 0;
}
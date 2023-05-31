#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX(lhs,rhs) (lhs>rhs?lhs:rhs)
#define MIN(lhs,rhs) (lhs>rhs?rhs:lhs)
using namespace std;
int main()
{
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	int W, H, w, h;
	cin >> W >> H >> w >> h;
	if ((MIN(w, h) <= MIN(W, H)) && (MAX(w, h) <= MAX(W, H)))
	{
		int noRot = (int)ceil(log2((double)W / w)) + (int)ceil(log2((double)H / h)),
			wtRot = (int)ceil(log2((double)W / h)) + (int)ceil(log2((double)H / w));
		cout << (MIN(noRot, wtRot));
	}
	else
	{
		cout << -1;
	}
	return 0;
}
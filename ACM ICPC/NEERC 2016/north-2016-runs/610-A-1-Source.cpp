#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;

long long min(long long a, long long b)
{
	if (a >= b)
		return b;
	return a;
}
long long max(long long a, long long b)
{
	if (a >= b)
		return a;
	return b;
}

int main()
{
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	long long w, h,ax,ay,bx,by = 0;
	cin >> w >> h;
	cin >> ax >> ay >> bx >> by;
	if (ax == bx)
	{
		cout << 0 << " " << min(ay, by)<<" "<<w<<" "<<max(ay,by);
		return 0;
	}
	cout << min(ax, bx) << " " << 0 << " " << max(ax, bx) << " " << h;
	return 0;
}
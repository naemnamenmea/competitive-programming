#include <iostream>
#include <iomanip> 
#include <math.h>
#include <string>
#include <vector>

using namespace std;

long max(long a, long b)
{
	if (a > b) return a;
	else return b;
}

long min(long a, long b)
{
	if (a > b) return b;
	else return a;
}

int main()
{
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);

	long w, h;
	long c1x, c1y, c2x, c2y;

	cin >> w >> h;
	cin >> c1x >> c1y >> c2x >> c2y;

	if (c1x == c2x) cout << 0 << " " << max(c1y, c2y) << " " << w << " " << min(c1y, c2y);
	else cout << min(c1x, c2x) << " " << 0 << " " << max(c1x, c2x) << " " << h;

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c;
	int n;
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	cin >> a >> b >> c;
	int d = a + b * 40 + c * 40 * 12;
	cin >> n;
	int ans = 0, cd = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		int now = x + y * 40 + z * 40 * 12;
		now += 18 * 40 * 12;
		if (now <= d && now > cd) {
			ans = i+1;
			cd = now;
		}
	}
	if (ans == 0)
		cout << -1;
	else
		cout << ans;
	return 0;
}

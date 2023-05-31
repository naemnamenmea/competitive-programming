#include <iostream>
#include <vector>
#include <map>
#include <set>

typedef long long ll;
using namespace std;
int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	int y, m, d;
	cin >> d >> m >> y;
	d++;
	if (d > days[m - 1])
	{
		d = 1;
		m++;
		if (m > 12)
		{
			m = 1;
			y++;
		}
	}
	int n;
	cin >> n;
	int ty, tm, td;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> td >> tm >> ty;
		bool flag = (ty < y - 18) || (ty == y - 18 && tm < m) || (ty == y - 18 && tm == m && td <= d);
		res += flag;
		//cout << flag << endl;
	}
	if (res == 0)
	{
		cout << -1;
	}
	else
	{
		cout << res;
	}
	return 0;
}
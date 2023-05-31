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
	for (int i = 1; i < 12; i++)
	{
		days[i] = days[i - 1] + days[i];
	}
	int n;
	cin >> n;
	int ty, tm, td;
	int res = 0;
	int tmin, min = 0, mini = -1;
	tm = min;
	for (int i = 0; i < n; i++)
	{
		cin >> td >> tm >> ty;
		bool flag = (ty < y - 18) || (ty == y - 18 && tm < m) || (ty == y - 18 && tm == m && td <= d);
		if (!flag)
			continue;
		tmin = ty * 365 + days[tm - 1];
		//cout << tmin << endl;
		if (tmin > min)
		{
			min = tmin;
			mini = i + 1;
		}
	}
	cout << mini;
	return 0;
}
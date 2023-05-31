#include<iostream>

using namespace std;

int main()
{
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	int d, m, y;
	cin >> d >> m >> y;
	int n,min_y1(0),min_m1(0),min_d1(0),ans(-2);
	cin >> n;
	bool flag = false;
	for (int i(0); i < n; i++)
	{
		int d1, m1, y1;
		cin >> d1 >> m1 >> y1;
		if ((y - y1) > 18) flag = true;
		if ((y - y1) == 18)
		{
			if ((m1 < m)) flag = true;
			if ((m == m1))
			{
				if (d >= d1) flag = true;
            }
		}
		if (flag)
		{
			if (y1 > min_y1) { min_y1 = y1; min_m1 = m1; min_d1 = d1; ans = i; }
			if (y1 == min_y1)
			{
				if (m1 > min_m1){ min_m1 = m1; min_d1 = d1; ans = i; }
				if (m1 == min_m1)
				{
					if (d1 > min_m1){ min_d1 = d1; ans = i;}
                }
			}
		}
		flag = false;
    }
	cout << ans+1;
	return 0;
}
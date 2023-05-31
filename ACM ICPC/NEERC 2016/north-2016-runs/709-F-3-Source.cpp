#include "iostream"
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()

{
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	int a, b, a1, b1,count=0;
	cin >> a >> b >> a1 >> b1;
	if ((a == a1 && b == b1) || (a == b1 && b == a1))
	{
		cout << "0";
		return 0;
	}
	if (a<a1 || b<b1)
	{
		int x = a;
		a = b;
		b = x;
	}
	if (a < a1 || b < b1)
	{
		cout << "-1";
		return 0;
	}
	while (a != a1 || b != b1)
	{
		if (a / 2 + a % 2 > a1)
		{
			count++;
			a = a / 2 + a % 2;
		}
		else if (a > a1)
		{
			count++;
			a = a1;
		}
		if (b / 2 + b % 2 > b1)
		{
			count++;
			b = b / 2 + b % 2;
		}
		else if (b > b1)
		{
			count++;
			b = b1;
		}
	}
	if (count == -1) cout << "-1"; else cout << count;
	//system("pause");
	return 0;
}
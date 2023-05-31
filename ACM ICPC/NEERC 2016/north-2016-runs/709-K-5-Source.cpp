#include "iostream"
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool func(int *a, int *b)
{
	if (b[2] > a[2]) return true; else
		if (b[2] == a[2])
			if (b[1] > a[1]) return true; else
				if (b[1] == a[1])
					if (b[0] > a[0]) return true;
	return false;
}

bool func2(int *a, int *b)
{
	if (b[2] - a[2] > 18) return true; else
		if (b[2] - a[2] == 18)
			if (b[1] - a[1] > 0) return true; else
				if (b[1] - a[1] == 0)
					if (b[0] >= a[0]) return true;
	return false;
}

int main()

{
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	int mas0[3];
	int mas1[3];
	mas1[0] = 0;
	mas1[1] = 0;
	mas1[2] = 0;
	int **mas;
	int n;
	int count = 0;
	cin >> mas0[0] >> mas0[1] >> mas0[2];
	cin >> n;
	mas = new int*[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[3];
		cin >> mas[i][0] >> mas[i][1] >> mas[i][2];
	}
	for (int i = 0; i <n; i++)
	{
		if (func2(mas[i], mas0) && func(mas1, mas[i]))
		{
			mas1[0] = mas[i][0];
			mas1[1] = mas[i][1];
			mas1[2] = mas[i][2];
			count = i + 1;
		}
	}
	if (count > 0) cout << count; else cout << "-1";

	//system("pause");
	return 0;
}
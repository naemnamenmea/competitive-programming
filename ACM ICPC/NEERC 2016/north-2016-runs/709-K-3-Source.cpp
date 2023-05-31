#include "iostream"
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool func(int *a, int *b)
{
	if (a[2] > b[2]) true; else
		if (a[2] == b[2])
			if (a[1] > b[2]) true; else
				if (a[0] > b[0]) true;
	return false;
}

int main()

{
		freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);

	int day, month, year;
	int mas1[3];
	mas1[0] = 0;
	mas1[1] = 0;
	mas1[2] = 0;
	int **mas;
	int n;
	int count = 0;
	cin >> day >> month >> year;
	cin >> n;
	mas = new int*[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[3];
		cin >> mas[i][0] >> mas[i][1] >> mas[i][2];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (year - mas[i][2] > 18) {
			if (func(mas[i], mas1)) continue;
			count = i + 1;
			mas1[0] = mas[i][0];
			mas1[1] = mas[i][1];
			mas1[2] = mas[i][2];
		}
		else
		{
			if (year - mas[i][2] == 18)
			{
				if (month - mas[i][1] > 0) {
					if (func(mas[i], mas1)) continue;
					count = i + 1;
					mas1[0] = mas[i][0];
					mas1[1] = mas[i][1];
					mas1[2] = mas[i][2];
				}
				else
				{
					if (month - mas[i][1] == 0)
						if (day - mas[i][0] >= 0)
						{
						if (func(mas[i], mas1)) continue;
						count = i + 1;
						mas1[0] = mas[i][0];
						mas1[1] = mas[i][1];
						mas1[2] = mas[i][2];
						}
				}
			}
		}
	}
	if (count > 0) cout << count; else cout << "-1";

	//system("pause");
	return 0;
}
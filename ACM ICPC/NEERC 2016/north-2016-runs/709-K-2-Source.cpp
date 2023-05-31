#include "iostream"
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()

{
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	
	int day, month, year;
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
			count = i + 1;
			break;
		}
		else
		{
			if (year - mas[i][2] == 18)
			{
				if (month - mas[i][1] > 0) {
					count = i + 1;
					break;
				}
				else
				{
					if (month - mas[i][1] == 0)
						if (day - mas[i][0] >= 0)
						{
						count = i + 1;
						break;
						}
				}
			}
		}
	}
	if (count > 0) cout << count; else cout << "-1";

	//system("pause");
	return 0;
}
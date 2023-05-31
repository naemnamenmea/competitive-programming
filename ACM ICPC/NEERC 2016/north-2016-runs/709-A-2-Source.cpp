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
		freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);

	//int day, month, year;
	//int mas1[3];
	//mas1[0] = 0;
	//mas1[1] = 0;
	//mas1[2] = 0;
	//int **mas;
	//int n;
	//int count = 0;
	//cin >> day >> month >> year;
	//cin >> n;
	//mas = new int*[n];
	//for (int i = 0; i < n; i++)
	//{
	//	mas[i] = new int[3];
	//	cin >> mas[i][0] >> mas[i][1] >> mas[i][2];
	//}
	//for (int i = n - 1; i >= 0; i--)
	//{
	//	if (year - mas[i][2] > 18) {
	//		if (func(mas[i], mas1)) continue;
	//		count = i + 1;
	//		mas1[0] = mas[i][0];
	//		mas1[1] = mas[i][1];
	//		mas1[2] = mas[i][2];
	//	}
	//	else
	//	{
	//		if (year - mas[i][2] == 18)
	//		{
	//			if (month - mas[i][1] > 0) {
	//				if (func(mas[i], mas1)) continue;
	//				count = i + 1;
	//				mas1[0] = mas[i][0];
	//				mas1[1] = mas[i][1];
	//				mas1[2] = mas[i][2];
	//			}
	//			else
	//			{
	//				if (month - mas[i][1] == 0)
	//					if (day - mas[i][0] >= 0)
	//					{
	//					if (func(mas[i], mas1)) continue;
	//					count = i + 1;
	//					mas1[0] = mas[i][0];
	//					mas1[1] = mas[i][1];
	//					mas1[2] = mas[i][2];
	//					}
	//			}
	//		}
	//	}
	//}
	//if (count > 0) cout << count; else cout << "-1";
	long long w, h, ax, ay, bx, by;
	cin >> w >> h >> ax >> ay >> bx >> by;
	
	if (abs(ax - bx) >= 2)
	{
		if (ax < bx)
		{
			cout << ax + 1 << " " << 0 << " " << ax + 1 << " " << h;
		}
		else
		{
			cout << bx + 1 << " " << 0 << " " << bx + 1 << " " << h;
		}
	}
	else
	{
		if (abs(ay - by) >= 2)
		{
			if (ay < by)
			{
				cout << 0 << " " << by - 1 << " " << w <<" "<< by - 1;
			}
			else
			{
				cout << 0 << " " << ay - 1 << " " << w <<" "<< ay - 1;
			}

		}
		if (ax != bx && ay == by)
		{
			cout << ax << " " << 0 <<" "<< bx << " " << h;
		}
		if (ax == bx && ay != by)
		{
			cout << 0 << " " << by << " " << w << " " << ay;
		}
	}



	//system("pause");
	return 0;
}
//#include "iostream"
//#include <cstdio>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//
//using namespace std;
//
//int main()
//
//{
//	freopen("folding.in", "r", stdin);
//	freopen("folding.out", "w", stdout);
//	long long a, b, a1, b1, count = 0;
//	cin >> a >> b >> a1 >> b1;
//	if ((a == a1 && b == b1) || (a == b1 && b == a1))
//	{
//		cout << "0";
//		return 0;
//	}
//	if (a<a1 || b<b1)
//	{
//		long long x = a;
//		a = b;
//		b = x;
//	}
//	if (a < a1 || b < b1)
//	{
//		cout << "-1";
//		return 0;
//	}
//	while (a != a1 || b != b1)
//	{
//		if (a / 2 + a % 2 > a1)
//		{
//			count++;
//			a = a / 2 + a % 2;
//		}
//		else if (a > a1)
//		{
//			count++;
//			a = a1;
//		}
//		if (b / 2 + b % 2 > b1)
//		{
//			count++;
//			b = b / 2 + b % 2;
//		}
//		else if (b > b1)
//		{
//			count++;
//			b = b1;
//		}
//	}
//	if (count == -1) cout << "-1"; else cout << count;
//	//system("pause");
//	return 0;
//}
#include "iostream"
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()

{
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n;
	cin >> n;
	vector< int> mas(n);
	vector <int> mas2(n);
	vector <int> mas3(n, 0);
	for (int i = 0; i < n; i++)
		cin >> mas[i] >> mas2[i];
	int j = 0; int max;
	while (j < n)
	{
		if (mas[j] < mas2[j])
		{
			max = mas2[j];
		}
		else max = mas[j];
		for (int i = 0; i < n; i++)
			if (i != j)
			{
			if (mas[i] <= max || mas2[i] <= max)
				mas3[j]++;
			}
		j++;
	}
	for (int i = 0; i < n; i++)
		cout << mas3[i] << endl;




	//system("pause");
	return 0;
}
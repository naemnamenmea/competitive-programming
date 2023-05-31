//#include "iostream"
//#include <cstdio>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//
//using namespace std;
//
//struct para
//{
//	int num1;
//	int num2;
//};
//
//int main()
//
//{
//	//freopen("codecoder.in", "r", stdin);
//	//freopen("codecoder.out", "w", stdout);
//	/*int n;
//	cin >> n;
//	para a;
//	vector <para> v;
//	vector <int> v1;
//	v1.assign(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//	cin >> a.num1 >> a.num2;
//	v.push_back(a);
//	}
//	for (int i = 0; i < n; i++)
//	{
//	for (int j = 0; j < n; j++)
//	{
//	if (j != i)
//	{
//	if (v[i].num1 > v[j].num1 || v[i].num2 > v[j].num2) v1[i]++;
//	}
//	}
//	}
//	for (int i = 0; i < n; i++) cout << v1[i] << endl;*/
//	int y, x, a, b, ch = 0;
//	cin >> y >> x >> a >> b;
//	bool fl = true;
//
//
//		if (a > y && x > b) swap(a, b);
//		if (y > a && b > x) swap(a, b);
//	
//	while (x > b)
//	{
//		//if (x / 2 + x % 2 > b)
//		{
//			x = x / 2 + x % 2; ch++;
//		}
//		else { x = b; ch++; }
//	}
//	while (y > a)
//	{
//		if (y / 2 + y % 2 > a)
//		{
//			y = y / 2 + y % 2; ch++;
//		}
//		else { y = a; ch++; }
//	}
//	cout << ch;
//
//	system("pause");
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
freopen("folding.in", "r", stdin);
freopen("folding.out", "w", stdout);
	long long a, b, a1, b1, count = 0;
	cin >> a >> b >> a1 >> b1;
	if ((a == a1 && b == b1) || (a == b1 && b == a1))
	{
		cout << "0";
		return 0;
	}
	if (a<a1 || b<b1)
	{
		long long x = a;
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
		if (a / 2 + a % 2 == b1)
		{
			long long x = a;
			a = b;
			b = x;
		}
		else if (b / 2 + b % 2 == a1)
		{
			long long x = a;
			a = b;
			b = x;
		}
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
	if (count == -1) cout << "-1"; 
	else cout << count;
	//system("pause");
	return 0;
}
#include "iostream"
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct para
{
	int num1;
	int num2;
};

int main()

{
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n;
	cin >> n;
	para a;
	vector <para> v;
	vector <int> v1;
	v1.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a.num1 >> a.num2;
		v.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				if (v[i].num1 > v[j].num1 || v[i].num2 > v[j].num2) v1[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << v1[i] << endl;
	//system("pause");
	return 0;
}
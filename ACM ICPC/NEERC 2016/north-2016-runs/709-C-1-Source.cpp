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
	vector <int> mas3(n,0);
	for (int i = 0; i < n; i++)
		cin >> mas[i] >> mas2[i];
	int j = 0; int max;
	while (j < n)
	{
		if (mas[j] < mas2[j])
			{
			max = mas[j];
			}
			else max = mas2[j];
		for (int i = 0; i < n; i++)
			if ( i != j)
			{
				if (mas[i] <= max || mas2[i] <= max)
					mas3[j]++;
			}
			j++;
	}
	for (int i = 0; i < n; i++)
		cout << mas3[i]<<endl;




	//system("pause");
	return 0;
}
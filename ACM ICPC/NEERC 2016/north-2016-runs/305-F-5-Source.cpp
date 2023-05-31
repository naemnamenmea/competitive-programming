#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
	int ax, ay, bx, by;

	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);

	cin >> ax >> ay >> bx >> by;
	if (ay>ax) swap(ax, ay);
	if (by>bx) swap(bx, by);

	if (ay<by || ax<bx)
	{
		cout << -1;
		fclose(stdout);
		return 0;
	}

	double h = (double)ax / bx;

	int c_1 = ceil(log2((double)ay / bx));
	int c_2 = ceil(log2((double)ax / by));

	int count2 = -1;

	int count1 = ceil(log2((double)ax / bx)) + ceil(log2((double)ay / by));
	if (c_1>=0 && c_2>=0)
		count2 = c_1 + c_2;
	
	if (count2 >= 0 && count1 >= 0)
	{
		if (count2 < count1) count1 = count2;
	}
	else
	{
		if (count1 >= 0) goto her;
		if (count2 >= 0)
		{
			count1 = count2;
			goto her;
		}
		count1 = -1;
	}
	her:
	cout << count1;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
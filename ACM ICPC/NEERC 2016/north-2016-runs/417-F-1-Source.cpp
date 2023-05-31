#include <iostream>
#include <iomanip> 
#include <math.h>
#include <string>
#include <vector>

using namespace std;
long couts=0;

void flod(long a, long b)
{
	while (a > b) 
	{
		a = a % 2 + a / 2;
		couts++;
	}

}



int main()
{
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);

	long a1, a2, b1, b2;

	cin >> a1 >> b1 >> a2 >> b2;

	if (b1 > a1) swap(a1, b1);
	if (b2 > a2) swap(a2, b2);

	if (a1 >= a2 && b1 >= b2)
	{
		flod(a1, a2);
		flod(b1, b2);
		cout << couts;
	}
	else cout << -1;

	return 0;
}
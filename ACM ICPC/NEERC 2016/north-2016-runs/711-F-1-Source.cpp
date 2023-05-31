#include<iostream>
#include<math.h>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	int a, b, w, h;
	cin >> a >> b >> w >> h;
	if (h > max(a, b) || w > max(a, b)){
		cout << -1;
		return 0;
	}
	if (a < b)
		swap(a, b);
	if (w < h)
		swap(w, h);
	int k = 0;
	while ((a + 1) >> 1 > w)
	{
		k++;
		a = (a + 1) >> 1;
	}
	if(a!=w)
	k++;
	while ((b + 1) >> 1 > h)
	{
		k++;
		b = (b + 1) >> 1;
	}
	if(b!=h)
		k++;
	cout << k;
	return 0;
}
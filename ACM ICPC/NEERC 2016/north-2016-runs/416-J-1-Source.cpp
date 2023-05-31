#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define a1 max(rand() % 256, rand() % 256)
#define b1 max(a1, a1)
#define c1 max(b1, b1)
#define d1 max(c1, c1)
#define e1 max(d1, d1)
#define f1 max(e1, e1)
#define g1 max(f1, f1)
#define h1 max(g1, g1)
#define i1 max(h1, h1)

using namespace std;

int ans[256];

int main()
{
	int n;
	freopen("java2016.in", "r", stdin);
	freopen("java2016.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (char i = 'a'; i < 'a' + 17; i++)
	{
		if (i == 'a')
			cout << "a = ? max ?" << endl;
		else
			cout << i << " = " << (char)(i - 1) << " max " << (char)(i - 1) << endl;
	}
	cout << "s = r / c" << endl;
	for (char i = 't'; i < 't' + 7; i++)
	{
		cout << i << " = " << (char)(i - 1) << " + " << (char)(i - 1) << endl;
	}

	vector<int> arr;
	
	if (n == 0)
	{
		cout << "? / ? / ?";
		return 0;
	}

	int cnt = 0;
	while (n > 0)
	{
		if (n % 2 != 0)
		{
			arr.push_back(cnt);
		}
		n /= 2;
		cnt++;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		if (i == 0)
			cout << (char)('s'+arr[i]);
		else
			cout << " + " << (char)('s' + arr[i]);
	}
	return 0;
}
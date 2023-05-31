#include <iostream>
#include <algorithm>

using namespace std;

int dfs(int a, int b, int c, int d)
{
	if (a == c && b == d)
		return 0;
	if (a == c)
		return 1 + dfs(a, max((b + 1) / 2, d), c, d);
	if (b == d)
		return 1 + dfs(max((a + 1) / 2, c), b, c, d);
	return 2 + dfs(max((a + 1) / 2, c), max((b + 1) / 2, d), c, d);
}

int main()
{
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	 int a, b;
	 int c, d;

	 cin >> a >> b;
	 cin >> c >> d;
	 if (a < b)
		 swap(a, b);
	 if (c < d)
		 swap(c, d);

	 if (a < c || b < d)
	 {
		 cout << -1;
		 return 0;
	 }

	 cout << dfs(a, b, c, d);
}
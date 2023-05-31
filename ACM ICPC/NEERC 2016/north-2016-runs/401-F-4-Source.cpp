#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	 ll a, b;
	 ll c, d;

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

	 ll len = 0;
	 while (a != c || b != d)
	 {
		 len++;
		 if (c < d) swap(c, d);

		 if (a != c) c = min(2 * c, a);
		 else d = min(2 * d, b);

		 if (c < d) swap(c, d);
	 }
	 cout << len;
}
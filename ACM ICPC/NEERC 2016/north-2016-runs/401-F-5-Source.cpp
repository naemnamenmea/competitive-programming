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

	 ll len1 = 0;
	 ll a_new = c;
	 ll b_new = d;

	 while (a_new < a)
		 len1++, a_new = min(2 * a_new, a);
	 while (b_new < b)
		 len1++, b_new = min(2 * b_new, b);

	 ll len2 = 0;
	 a_new = c;
	 b_new = d;

	 while (a_new < b)
		 len2++, a_new = min(2 * a_new, b);
	 while (b_new < a)
		 len2++, b_new = min(2 * b_new, a);

	 cout << min(len1, len2);
}
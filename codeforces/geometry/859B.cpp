#ifdef codeforces_859B

#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {

	int n;
	cin >> n;
	int a = sqrt(n);
	int r = n - a * a;
	int res = 4 * a;

	while (r > 0) {
		res += 2;
		r -= min(r, a);
	}

	cout << res;

	return 0;
}

#endif // codeforces_859B
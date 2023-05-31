//#define dance_school
#ifdef dance_school

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

constexpr int N = 1e6 + 1;

vector<ll> cache(N);

//int f(int x) {
//	if (x == 0) return 0;
//	if (x == 1) return 1;
//	return f(x - 1) * 2 - f(x - 2) + 1;
//}

int main() {
	freopen("input.txt", "r", stdin);

	//cout << f(4) + f(2) << endl;

	int n, pairs;
	string s;
	cin >> n >> s;

	pairs = int(n / 2);

	cache[0] = 0;
	cache[1] = 1;
	for (int i = 2; i <= pairs; ++i) {
		cache[i] = cache[i - 1] * 2 - cache[i - 2] + 1;
	}

	int len = s.size();
	ll res = 0;
	char prev = s[0];
	for (int i = 1; i < len; ++i) {
		ll top = 0;
		if (s[i] != prev) {

		}
	}

	cout << res << endl;

	return 0;
}

#endif // dance_school
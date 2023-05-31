#if !defined(LOCAL_KONTROL) || defined(F_24_03_2017)

#include <iostream>
#include <algorithm>
#include <vector>

#ifdef LOCAL_KONTROL
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

constexpr auto EPS = 1e-7;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef LOCAL_KONTROL
	ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

	size_t n;
	int t, x, d;

	cin >> n >> t;

	vector<double> v(2 * n);

	int i = 0;

	while (n--) {
		cin >> x >> d;
		v[i++] = x - d / 2.;
		v[i++] = x + d / 2.;
	}

	sort(begin(v), end(v));

	size_t res = 2;

	for (size_t i = 1; i + 1 < v.size(); i += 2) {
		double dist = v[i + 1] - v[i];
		if (dist >= t) {
			res += dist - t < EPS ? 1 : 2;
		}
	}

	cout << res;

	return 0;
}

#endif // F_24_03_2017
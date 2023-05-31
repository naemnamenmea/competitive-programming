#if !defined(LOCAL_KONTROL) || defined(B_24_03_2017)

#include <iostream>

#ifdef LOCAL_KONTROL
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef LOCAL_KONTROL
	ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

	int n, d;
	int prev, cur;
	int res = 0;

	cin >> n >> d;
	cin >> prev;
	--n;
	while (n--) {
		cin >> cur;

		if (prev < cur) {
			prev = cur;
			continue;
		}

		int diff = prev - cur + 1;

		int count = diff / d + !!(diff % d);
		res += count;
		prev = cur + d * count;
	}

	cout << res;

	return 0;
}

#endif // B_24_03_2017
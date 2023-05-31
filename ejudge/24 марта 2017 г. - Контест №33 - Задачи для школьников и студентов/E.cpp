#if !defined(LOCAL_KONTROL) || defined(E_24_03_2017)

#include <iostream>
#include <algorithm>
#include <vector>

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

	size_t n, m;
	cin >> n >> m;

	size_t min_x = m, min_y = n, max_x = 0, max_y = 0;

	vector<vector<char>> a(n, vector<char>(m));

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			cin >> a[i][j];

			if (a[i][j] == '*') {
				min_x = min(min_x, j);
				min_y = min(min_y, i);
				max_x = max(max_x, j);
				max_y = max(max_y, i);
			}
		}
	}

	++max_x;
	++max_y;

	for (size_t i = min_y; i < max_y; ++i) {
		for (size_t j = min_x; j < max_x; ++j) {
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}

#endif // E_24_03_2017
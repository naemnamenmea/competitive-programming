#if !defined(LOCAL_KONTROL) || defined(C_24_03_2017)

#include <iostream>
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

	int n = 3;
	vector<vector<char>> m(n, vector<char>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> m[i][j];
		}
	}

	int res = true;

	for (size_t i = 0; i * 2 < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			if (m[i][j] != m[n - i - 1][n - j - 1]) {
				res = false;
				goto out;
			}
		}
	}

out:

	cout << (res ? "YES" : "NO");

	return 0;
}

#endif // C_24_03_2017
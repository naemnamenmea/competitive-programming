#if !defined(LOCAL_KONTROL) || defined(B_31_03_2017)

#include <iostream>
#include <algorithm>
#include <string>

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

	string str;

	cin >> str;

	size_t res = 0;

	for (size_t i = 1; i < str.size(); ++i) {
		size_t tmp = 0;
		for (size_t j = 0; j < str.size() - i; ++j) {
			if (str[i+j] != str[j]) {
				tmp = 0;
			}
			else {
				res = max(res, ++tmp);
			}
		}
	}

	cout << res;

	return 0;
}

#endif // B_31_03_2017
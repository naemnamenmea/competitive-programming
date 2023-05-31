#if !defined(LOCAL_KONTROL) || defined(A_31_03_2017)

#include <iostream>
#include <regex>
#include <algorithm>

#ifdef LOCAL_KONTROL
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

using namespace std;

bool check(const string& str) {
	if (str.empty())
		return true;

	size_t from = str.find_first_of('@') + 1;
	size_t to = min(str.find_first_of('/', from), str.find_first_of('?', from));
	to = min(str.size() - 1, to);

	return to - from <= 32;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef LOCAL_KONTROL
	ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

	string str;

	getline(cin, str);

	regex re("\\w{1,16}@\\w{1,16}(\\.\\w{1,16})*(/\\w{1,16})?");

	cout << (regex_match(str, re) && check(str) ? "YES" : "NO");

	return 0;
}

#endif // A_31_03_2017
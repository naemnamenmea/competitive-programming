#ifdef codeforces_766B

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const fs::path ROOT = fs::path(__FILE__).parent_path();
	ifstream ifs(ROOT / "input.txt"); cin.rdbuf(ifs.rdbuf());

	int n;
	cin >> n;
	vector<int> segment(n);

	for (int i = 0; i < n; ++i) {
		cin >> segment[i];
	}

	sort(begin(segment), end(segment), ::less<int>());

	bool res = false;

	for (size_t i = 1; i + 1 < n; ++i) {
		if (segment[i - 1] + segment[i] > segment[i + 1]) {
			res = true;
			break;
		}
	}

	cout << (res ? "YES" : "NO") << endl;

	return 0;
}

#endif // codeforces_766B
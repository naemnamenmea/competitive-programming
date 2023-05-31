#ifdef codeforces_1047B

#include <fstream>
#include <iostream>
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
	ll max_dist = -1;
	int res = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;		
		res = max(res, x + y);
	}

	cout << res;

	return 0;
}

#endif // codeforces_1047B
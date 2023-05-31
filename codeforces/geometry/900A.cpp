#ifdef codeforces_900A

#include <fstream>
#include <iostream>
#include <vector>
#include <experimental/filesystem>

typedef long long ll;

namespace fs = std::experimental::filesystem;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef LOCAL_KONTROL
	fs::path ROOT = fs::path(__FILE__).parent_path();
	ifstream ifs(ROOT / "input.txt"); cin.rdbuf(ifs.rdbuf());
#endif // LOCAL_KONTROL

	int n;
	cin >> n;
	bool res = true;
	int xl_count = 0, xr_count = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;
		if (x < 0) {
			++xl_count;
		}
		else {
			++xr_count;
		}

		if (xl_count > 1 && xr_count > 1) {
			res = false;
			break;
		}
	}

	cout << (res ? "Yes" : "No");

	return 0;
}

#endif // codeforces_900A
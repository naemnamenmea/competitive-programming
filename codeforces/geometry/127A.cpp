#ifdef codeforces_127A

#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
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

	int n, k;

	cin >> n >> k;

	double x, y, prev_x, prev_y, total=0;

	cin >> prev_x >> prev_y;
	--n;

	while (n--) {
		cin >> x >> y;
		total += sqrt(pow(prev_x - x, 2) + pow(prev_y - y, 2));
		prev_x = x;
		prev_y = y;
	}

	cout << fixed << setprecision(10) << total / 50 * k;

	return 0;
}

#endif // codeforces_127A
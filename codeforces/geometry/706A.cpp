#ifdef codeforces_706A

#include <fstream>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const fs::path ROOT = fs::path(__FILE__).parent_path();
	ifstream ifs(ROOT / "input.txt"); cin.rdbuf(ifs.rdbuf());

	double a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	double res = numeric_limits<double>::max();
	while (n--) {
		double x, y, speed;
		cin >> x >> y >> speed;

		double dist = sqrt(pow(x - a, 2) + pow(y - b, 2));

		res = min(res, dist / speed);
	}

	cout << fixed << setprecision(10) << res;

	return 0;
}

#endif // codeforces_706A
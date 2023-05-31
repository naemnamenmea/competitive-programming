#ifdef codeforces_1199B

#include <fstream>
#include <iostream>
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

	double H, L;
	cin >> H >> L;
	cout << fixed << setprecision(10) << (H * H + L * L) / (2 * H) - H;


	return 0;
}

#endif // codeforces_1199B
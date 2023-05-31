#ifdef codeforces_224A

#include <fstream>
#include <iostream>
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

	int Sab, Sbc, Sac;

	cin >> Sab >> Sbc >> Sac;

	int c = sqrt((Sac * Sbc) / Sab);
	int a = Sac / c;
	int b = Sbc / c;

	cout << 4 * (a + b + c);

	return 0;
}

#endif // codeforces_224A
#ifdef codeforces_181A

#include <fstream>
#include <iostream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const fs::path ROOT = fs::path(__FILE__).parent_path();
	ifstream ifs(ROOT / "input.txt");
	auto cinbuf = cin.rdbuf(ifs.rdbuf());


	int n, m;
	int x = 0, y = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char symbol;
			cin >> symbol;
			if (symbol == '*') {
				x ^= i;
				y ^= j;
			}
		}
	}

	cout << x << ' ' << y;


	ifs.close();
	cin.rdbuf(cinbuf);

	return 0;
}

#endif // codeforces_181A
#if !defined(LOCAL_LAUNCH) || defined(A_Equalize_Prices_Again)

#include <iostream>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>

#ifdef LOCAL_LAUNCH
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  fs::path ROOT = fs::path(__FILE__).parent_path();
  ifstream ifs(ROOT / "input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    int sum = 0;
    for (int j = 0; j < n; ++j) {
      int v;
      cin >> v;
      sum += v;
    }

    cout << ceil(static_cast<double>(sum) / n - 1e-7) << endl;
  }

  return 0;
}

#endif // A_Equalize_Prices_Again
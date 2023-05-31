#if !defined(LOCAL_LAUNCH) || defined(codeforces_279A)

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

#ifdef LOCAL_LAUNCH
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif // LOCAL_LAUNCH

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  const fs::path ROOT = fs::path(__FILE__).parent_path();
  //ifstream ifs(ROOT / "input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  int a, b;
  cin >> a >> b;

  if (b == 0 && (a == 0 || a == 1)) {
    cout << 0;
    return 0;
  }

  int x = a, y = b;

  if (x < 0) {
    x = 4 * abs(x) - 1;
  }
  else {
    x = 4 * x - 3;
  }

  if (y < 0) {
    y = 4 * abs(y);
  }
  else {
    y = 4 * y - 2;
  }

  if (a > 0 && b < 0) {
  cout << (abs(a - 1) == abs(b) ? min(x, y) : max(x, y));
  }
  else {
  cout << (abs(a) == abs(b) ? min(x, y) : max(x, y));
  }

  return 0;
}

#endif // codeforces_279A
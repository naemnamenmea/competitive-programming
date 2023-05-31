#if !defined(LOCAL_LAUNCH) || defined(codeforces_141B)

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

  int a, x, y;
  cin >> a >> x >> y;

  if (y <= 0 || x <= -a || x >= a || y % a == 0) {
    cout << -1;
    return 0;
  }

  int res = (y / (2 * a)) * 3;

  if (y < a) {
    if (2 * abs(x) < a)
      res = 1;
    else {
      cout << -1;
      return 0;
    }
  }
  else if ((y / a) % 2 == 1) { // []
    if (2 * abs(x) < a) {
      res += 2;
    }
    else {
      cout << -1;
      return 0;
    }
  }
  else if ((y / a) % 2 == 0) { // []][]
    if (x == 0) {
      cout << -1;
      return 0;
    }
    else if (x > 0) {
      res += 1;
    }
  }

  cout << res;

  return 0;
}

#endif // codeforces_141B
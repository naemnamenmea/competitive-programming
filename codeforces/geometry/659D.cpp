#if !defined(LOCAL_LAUNCH) || defined(codeforces_659D)

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>

#ifdef LOCAL_LAUNCH
#include <experimental/filesystem>
#include "geometry.hpp"
#include "pretty_print.h"

namespace fs = std::experimental::filesystem;
#endif // LOCAL_LAUNCH

constexpr auto EPS = 1e-9;

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  fs::path ROOT = fs::path(__FILE__).parent_path();
  ifstream ifs(ROOT / "input.txt"); cin.rdbuf(ifs.rdbuf());
#endif // LOCAL_LAUNCH

  point3d<double> p[3];
  int n;
  cin >> n;
  n -= 2;

  for (size_t i = 1; i < 3; ++i) {
    double x, y;
    cin >> x >> y;
    p[i] = point3d<double>(x, y);
  }

  size_t res = 0;

  while (n--) {
    double x, y;
    cin >> x >> y;
    p[0] = p[1];
    p[1] = p[2];
    p[2] = point3d<double>(x, y);

    auto gg = (p[2] - p[1]) % (p[0] - p[1]);
    if (gg.z > 0) {
      ++res;
    }
  }

  cout << res;

  return 0;
}

#endif // codeforces_659D
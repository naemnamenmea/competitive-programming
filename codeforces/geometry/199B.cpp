#if !defined(LOCAL_LAUNCH) || defined(codeforces_199B)

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>

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

  double x1, x2, y1, y2, r1, r2, R1, R2;

  cin >> x1 >> y1 >> r1 >> R1;
  cin >> x2 >> y2 >> r2 >> R2;

  double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  bool a1 = r1 - d >= r2;
  bool a2 = R1 + d <= R2;
  bool a = a1 && a2;
  bool b1 = r2 - d >= r1;
  bool b2 = R2 + d <= R1;
  bool b = b1 && b2;

  if (isEqual(R2 + d, r1) || isEqual(R1 + d, r2)) {
    cout << 4;
  }
  else if (r1 + R2 <= d && R1 + r2 <= d
    || a
    || b) {
    cout << 2;
  }
  else if (r1 + d < r2 || r2 + d < r1
    || r1 + R2 <= d || R1 + r2 <= d) {
    cout << 1;
  }
  else {
    cout << 0;
  }

  return 0;
}

#endif // codeforces_199B
#if !defined(LOCAL_LAUNCH) || defined(codeforces_140A)

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

  int n;
  double R, r;

  cin >> n >> R >> r;

  if (2 * r <= R) {
    double realy = M_PI / asin(r / (R - r));

    cerr << "n = " << n << endl
      << "realy = " << realy << endl;
    cout << (static_cast<int>(realy + EPS) >= n ? "YES" : "NO");
  }
  else {
    cout << (r <= R && n == 1 ? "YES" : "NO");
  }

  return 0;
}

#endif // codeforces_140A
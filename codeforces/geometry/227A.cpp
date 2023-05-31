#if !defined(LOCAL_LAUNCH) || defined(codeforces_227A)

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#ifdef LOCAL_LAUNCH
#include <experimental/filesystem>
#include "geometry.hpp"

namespace fs = std::experimental::filesystem;
#endif // LOCAL_LAUNCH

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  fs::path ROOT = fs::path(__FILE__).parent_path();
  ifstream ifs(ROOT / "input.txt"); cin.rdbuf(ifs.rdbuf());
#endif // LOCAL_LAUNCH

  int n = 3;
  vector<point3d<double>> p(n);
  while (--n > -1) {
    double x, y;
    cin >> x >> y;
    p[n] = point3d<double>(x, y);
  }

  point3d<double> i(p[0] - p[1]);
  point3d<double> j(p[2] - p[1]);
  if (isZero(i * j)) {
    point3d<double> k = i % j;
    cout << (k.z < 0 ? "RIGHT" : "LEFT");
  }
  else {
    cout << "TOWARDS";
  }

  return 0;
}

#endif // codeforces_227A
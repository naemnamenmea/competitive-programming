#if !defined(LOCAL_LAUNCH) || defined(codeforces_9B)

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

  size_t n;
  double v_b, v_s;
  cin >> n >> v_b >> v_s;
  vector<double> v(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  double x_u, y_u;
  cin >> x_u >> y_u;

  size_t res = 2;
  double min_dist = sqrt(pow(v[2] - x_u, 2) + pow(y_u, 2));
  double min_time = v[2] / v_b + min_dist / v_s;

  for (size_t i = 3; i <= n; ++i) {
    double cur_dist = sqrt(pow(v[i] - x_u, 2) + pow(y_u, 2));
    double cur_time = v[i] / v_b + cur_dist / v_s;

    if (cur_time <= min_time) {
      if (!isEqual(cur_time, min_time) || cur_dist < min_dist) {
        res = i;
        min_time = cur_time;
      }
    }
  }

  cout << res;

  return 0;
}

#endif // codeforces_9B
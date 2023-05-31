#if !defined(LOCAL_LAUNCH) || defined(codeforces_908C)

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <cmath>
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

struct comparator {
  bool operator() (const pair<double, double>& lhs, const pair<double, double>& rhs) const {
    return lhs.second > rhs.second;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  fs::path ROOT = fs::path(__FILE__).parent_path();
  ifstream ifs(ROOT / "input.txt"); cin.rdbuf(ifs.rdbuf());
#endif // LOCAL_LAUNCH

  int n;
  double r;
  multiset < pair<double, double>, comparator > centers;

  cin >> n >> r;

  double d_sq = pow(2 * r, 2);

  while (n--)
  {
    double x, y = r;
    cin >> x;
    bool flag = true;
    for (const auto& [_x, _y] : centers) {
      if (!flag) {
        if (_y + r <= y - r)
          break;

        double delta_x_sq = pow(_x - x, 2);
        double dist = delta_x_sq + pow(_y - y, 2);

        if (dist < d_sq) {
          y += sqrt(d_sq - delta_x_sq) - sqrt(dist - delta_x_sq);
        }
      }

      if (flag) {
        if (_x - r <= x + r && _x + r >= x - r) {
          flag = false;
          double delta_y = sqrt(d_sq - pow(_x - x, 2));
          y = _y + delta_y;
        }
      }
    }

    centers.insert({ x, y });

    cout << fixed << setprecision(13) << y << ' ';
  }

  return 0;
}

#endif // codeforces_908C
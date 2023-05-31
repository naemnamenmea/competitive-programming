#if !defined(LOCAL_LAUNCH) || defined(C_polygon_area)

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

#ifdef LOCAL_LAUNCH
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

constexpr auto EPS = 1e-9;

typedef long long ll;

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  fs::path root = fs::path(__FILE__).parent_path();
  ifstream ifs(root / "input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  int n;
  double first_x, first_y;
  double cur_x, cur_y;
  double prev_x, prev_y;
  cin >> n;
  cin >> first_x >> first_y;
  prev_x = first_x;
  prev_y = first_y;
  --n;
  double res = 0;
  while (n--) {
    cin >> cur_x >> cur_y;

    res += prev_x * cur_y - prev_y * cur_x;

    prev_x = cur_x;
    prev_y = cur_y;
  }

  res += prev_x * first_y - prev_y * first_x;
  res = abs(res) / 2.;

  cout << fixed << setprecision(1) << res;

  return 0;
}

#endif // C_polygon_area
#if !defined(LOCAL_LAUNCH) || defined(B_polar_angle_of_a_point)

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
  //ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  double x, y;

  cin >> x >> y;

  double res = atan2(y, x);
  if (res < 0) {
    res += 2 * M_PI;
  }

  cout << fixed << setprecision(6) << res << endl;

  return 0;
}

#endif // B_polar_angle_of_a_point
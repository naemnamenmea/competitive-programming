#if !defined(LOCAL_LAUNCH) || defined(D_axes_of_symmetry_of_a_quadrangle)

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

#ifdef LOCAL_LAUNCH
#include <fstream>
#include <experimental/filesystem>
#include "geometry.hpp"

namespace fs = std::experimental::filesystem;
#endif

constexpr auto EPS = 1e-9;

typedef long long ll;

using namespace std;

/*
Не валидное решение
*/
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  fs::path root = fs::path(__FILE__).parent_path();
  ifstream ifs(root / "input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  point3d<double> p[4], g;
  int res = 0;

  for (int i = 0; i < 4; ++i) {
    double x, y;
    cin >> x >> y;
    p[i].x = x;
    p[i].y = y;
  }

  if (isZero((p[0] - p[2]) * (p[1] - p[3]))) {
    intersect2d(line2d<double>(p[0], p[2]), line2d<double>(p[1], p[3]), g);

    if (isEqual(~(g - p[0]), ~(p[2] - g)))
      ++res;
    if (isEqual(~(g - p[1]), ~(p[3] - g)))
      ++res;
  }

  if (isZero(((p[0] + p[1]) / 2. - (p[2] + p[3]) / 2.) * ((p[1] + p[2]) / 2. - (p[3] + p[0]) / 2.))) {

    if (isEqual(~(p[0] - p[1]), ~(p[2] - p[3])))
      ++res;
    if (isEqual(~(p[1] - p[2]), ~(p[3] - p[0])))
      ++res;
  }

  cout << res;

  return 0;
}

#endif // D_axes_of_symmetry_of_a_quadrangle
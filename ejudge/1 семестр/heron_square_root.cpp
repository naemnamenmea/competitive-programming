#if !defined(LOCAL_LAUNCH) || defined(heron_square_root)

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

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  //ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  double a;
  cin >> a;

  int n = 0;
  double x_prev = a;
  double x_next;

  while (true) {
    ++n;
    x_next = (x_prev + a / x_prev) / 2.;
    if (x_prev - x_next < EPS)
      break;
    x_prev = x_next;
  }

  cout << fixed << setprecision(10) << x_prev << endl;
  cout << n << endl;

  return 0;
}

#endif // heron_square_root
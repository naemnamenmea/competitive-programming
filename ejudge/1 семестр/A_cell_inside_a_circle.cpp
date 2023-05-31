#if !defined(LOCAL_LAUNCH) || defined(A_cell_inside_a_circle)

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

  int r;
  cin >> r;

  int res = 0;

  for (int i = 1; i < r; ++i) {
    res += floor(sqrt(r*r-i*i));
  }

  res *= 4;

  cout << res;

  return 0;
}

#endif // A_cell_inside_a_circle
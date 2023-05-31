#if !defined(LOCAL_LAUNCH) || defined(exponent)

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>

#ifdef LOCAL_LAUNCH
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

constexpr auto EPS = 1e-11;

typedef long long ll;

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  //ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  double sum = 1;
  int n = 0;
  double component = 1;

  double x;
  cin >> x;

  while (component > EPS) {
    sum += component;
    component *= x / ++n;
  }

  cout << fixed << setprecision(9) << sum;

  return 0;
}

#endif // exponent
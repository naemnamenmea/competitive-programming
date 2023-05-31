#if !defined(LOCAL_LAUNCH) || defined(horner_scheme)

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

  ll a, n, m;

  cin >> a >> n >> m;

  ll prev, next;
  prev = next = 1;
  while (n--) {
    prev = (1 + a * next) % m;
    next = prev;
  }

  cout << prev;

  return 0;
}

#endif // horner_scheme
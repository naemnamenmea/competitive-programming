#if !defined(LOCAL_LAUNCH) || defined(codeforces_contest_582_A_Chips_Moving)

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

#ifdef LOCAL_LAUNCH
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

constexpr auto EPS = 1e-7;

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  fs::path ROOT = fs::path(__FILE__).parent_path();
  ifstream ifs(ROOT / "/../input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  int n, odd = 0, even = 0;
  cin >> n;
  while (n--) {
    size_t num;
    cin >> num;

    num % 2 ? ++odd : ++even;
  }

  cout << min(odd, even);

  return 0;
}

#endif // codeforces_contest_582_A_Chips_Moving
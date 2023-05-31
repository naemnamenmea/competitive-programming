#if !defined(LOCAL_LAUNCH) || defined(codeforces_650A)

#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

#ifdef LOCAL_LAUNCH
#include <experimental/filesystem>
#include "pretty_print.h"
#include "geometry.hpp"

namespace fs = std::experimental::filesystem;
#endif // LOCAL_LAUNCH

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  fs::path ROOT = fs::path(__FILE__).parent_path();
  ifstream ifs(ROOT / "input.txt"); cin.rdbuf(ifs.rdbuf());
#endif // LOCAL_LAUNCH

  int n;
  unsigned long long res = 0;
  map<pair<int, int>,size_t> _xy;
  map<int,size_t> _x;
  map<int,size_t> _y;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    res += _x[x]++ + _y[y]++ - _xy[{x, y}]++;
  }  

  cout << res;

  return 0;
}

#endif // codeforces_650A
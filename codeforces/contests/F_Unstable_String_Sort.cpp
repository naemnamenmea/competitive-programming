#if !defined(LOCAL_LAUNCH) || defined(codeforces_contest_582_F_Unstable_String_Sort)

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

/*
5 3
1 5 2 4 3
5 3 1 2 4
*/

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  fs::path ROOT = fs::path(__FILE__).parent_path();
  ifstream ifs(ROOT / "/../input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  int n, k;
  cin >> n >> k;

  vector<int> q(n);
  vector<int> p(n);
  string res;
  res.resize(n);

  for (size_t i = 0; i < n; ++i) {
    cin >> p[i];
  }

  for (size_t i = 0; i < n; ++i) {
    cin >> q[i];
  }

  char c = 'a' - 1;
  char max_symb = 'a';
  for (size_t i = 0; i < n; ++i) {
    if (q[i] != p[i]) {
      if (p[i] < i + 1 && p[i] <= q[i]) {
        res[i] = res[p[i] - 1];
      }
      else if (q[i] < i + 1 && q[i] <= p[i]) {
        res[i] = res[q[i] - 1];
      }
      else {
        c = (c + 1) % ('z' + 1);
        res[i] = c;
      }
    }
    else {
      c = (c + 1) % ('z' + 1);
      res[i] = c;
    }
    max_symb = max(max_symb, res[i]);
  }

  if (max_symb - 'a' + 1 < k) {
    cout << "NO" << endl;
  }
  else {
    cout << "YES" << endl;
    cout << res << endl;
  }

  return 0;
}

#endif // codeforces_contest_582_F_Unstable_String_Sort
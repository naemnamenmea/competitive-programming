#if !defined(LOCAL_LAUNCH) || defined(codeforces_contest_582_B_Bad_Prices)

#define _USE_MATH_DEFINES

#include <iostream>
#include <stack>
#include <queue>
#include <deque>
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

  int t;
  cin >> t;

  vector<int> a;
  vector<int> b;
  for (int i = 0; i < t; ++i) {
    int n, res = 0;
    cin >> n;
    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];     
    }

    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >=0; --i) {    
      b[i] = min(b[i+1], a[i]);
    }

    for (int i = 0; i < n - 1;++i) {
      if (a[i] > b[i+1]) {
        ++res;
      }
    }

    cout << res << endl;
  }

  return 0;
}

#endif // codeforces_contest_582_B_Bad_Prices
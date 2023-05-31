#include <iostream>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>

#ifdef LOCAL_LAUNCH
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  fs::path ROOT = fs::path(__FILE__).parent_path();
  ifstream ifs(ROOT / "input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  int Q;
  cin >> Q;

  vector<string> a(2);

  for (int q = 0; q < Q; ++q) {
    size_t n;
    cin >> n >> a[0] >> a[1];

    size_t j = 0;
    size_t prev_j = 0;
    bool flag = true;
    int prev_id = 3; // 3 - 6 valid
    for (size_t i = 0; i < n;) {
      int id = a[j][i] - '0';

      if (id == 1 || id == 2) {
        if (prev_j == j) {
          if (prev_id == 1 || prev_id == 2) {
            flag = false;
            break;
          }
        }
        else {
          if (prev_id > 2) {
            flag = false;
            break;
          }
        }
      }

      if (i + 1 >= n) {
        if (j == 0 && (id == 1 || id == 2)) {
          flag = false;
          break;
        }
        if (j == 1 && prev_j == 0 && (id == 1 || id == 2)) {
          flag = false;
          break;
        }
        if (j == 1 && prev_j == 1 && !(id == 1 || id == 2)) {
          flag = false;
          break;
        }
      }

      if (id > 2 && prev_id < 3 || id < 3 && prev_id>2) {
        prev_j = j == 0 ? 1 : 0;
      }
      prev_id = id;

      if (prev_id > 2 || id < 3) {
        ++i;
      }
      else {
        prev_j = j == 0 ? 1 : 0;
      }
    }

    cout << (flag ? "YES" : "NO") << endl;
  }

  return 0;
}
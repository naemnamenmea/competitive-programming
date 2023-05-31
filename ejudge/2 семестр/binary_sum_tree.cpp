#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#ifdef LOCAL_LAUNCH
#include <experimental/filesystem>
#include <fstream>
namespace fs = std::experimental::filesystem;
#endif

typedef long long ll;

int main() {
#ifdef LOCAL_LAUNCH
  fstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  size_t n, k;
  cin >> n >> k;
  n = pow(2, ceil(log(n) / log(2)));
  vector<ll> bstree(n * 2);

  auto adjusted_i = [&n](size_t i) {
    return i + n - 1;
  };

  auto update = [&bstree, &adjusted_i](size_t i, ll x) {
    i = adjusted_i(i);
    ll prev = bstree[i];
    ll cur = bstree[i] = x;

    while (i >>= 1) {
      ll tmp = bstree[i];
      cur = bstree[i] += cur - prev;
      prev = tmp;
    }
  };

  auto count_sum = [&bstree, &adjusted_i](size_t l, size_t r) -> ll {
    l = adjusted_i(l);
    r = adjusted_i(r);

    ll lmsum = 0;
    ll rmsum = 0;

    while (l != r) {
      if (l % 2 != 0) {
        lmsum += bstree[l - 1];
      }
      if (r % 2 == 0) {
        rmsum += bstree[r + 1];
      }
      l >>= 1;
      r >>= 1;
    }
    return bstree[l] - lmsum - rmsum;
  };

  while (k--) {
    int query;
    cin >> query;

    if (query == 1) {
      size_t i;
      ll x;
      cin >> i >> x;

      update(i, x);
    }
    else {
      size_t l, r;
      cin >> l >> r;

      cout << count_sum(l, r) << endl;
    }
  }
}
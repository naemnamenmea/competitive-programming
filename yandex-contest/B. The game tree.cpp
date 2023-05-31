#include "pretty_print.h"

#include <iostream>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

#ifdef LOCAL_LAUNCH
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

typedef long long ll;

using namespace std;

int n, k;
string s;
unordered_multimap<int, int> e;

int solve(int v, int depth) {
  int player = depth % 2 == 0 ? 1 : 2;
  int opponent = player == 1 ? 2 : 1;

  auto p = e.equal_range(v);

  if (p.first == p.second) { // leaf
    if (s[v] == '0') {
      return 0;
    }
    if (s[v] == '-') {
      //return depth - 1 >= k ? opponent : player;
      return depth - 1 >= k && (depth - 1 - k) % 2 == 0 ? opponent : player;
    }
    if (s[v] == '+') {
      //return depth - 2 >= k ? player : opponent;
      return depth - 2 >= k && (depth - 2 - k) % 2 == 0 ? player : opponent;
    }
  }

  int res = solve(p.first->second, depth + 1);

  if (res != player) {
    for (auto it = next(p.first); it != p.second; ++it) {
      int tmp = solve(it->second, depth + 1);
      if (player == tmp) {
        return player;
      }
      else if (tmp == 0) {
        res = tmp;
      }
    }
  }

  return res;
}
/*
  
  !!! WRONG SOLUTION !!! 

*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  cin >> n >> k >> s;

  for (int t = 1; t < n; ++t) {
    int from, to;
    cin >> from >> to;
    e.emplace(from - 1, to - 1);
  }
  int res = solve(0, 0);

  if (res == 1) {
    cout << "First";
  }
  else if (res == 2) {
    cout << "Second";
  }
  else {
    cout << "Draw";
  }

  return 0;
}

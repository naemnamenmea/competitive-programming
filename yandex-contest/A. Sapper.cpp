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

struct Cell {
  bool isVisited = false;
  bool isBomb = false;
};

void dfs(vector<vector<Cell>>& field, size_t i, size_t j) {
  if (field[i][j].isVisited || field[i][j].isBomb) {
    return;
  }

  field[i][j].isVisited = true;

  if (i > 0)
    dfs(field, i - 1, j);
  if (i + 1 < field.size())
    dfs(field, i + 1, j);
  if (j > 0)
    dfs(field, i, j - 1);
  if (j + 1 < field[0].size())
    dfs(field, i, j + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  size_t n, m, k;
  cin >> n >> m;
  vector<vector<Cell>> field(n, vector<Cell>(m));

  cin >> k;

  for (size_t t = 0; t < k; ++t) {
    size_t i, j;
    cin >> i >> j;
    field[i - 1][j - 1].isBomb = true;
  }

  size_t res = 0;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      if (!field[i][j].isVisited && !field[i][j].isBomb) {
        ++res;
        dfs(field, i, j);
      }
    }
  }

  cout << res;

  return 0;
}

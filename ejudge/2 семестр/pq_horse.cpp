#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cell {
  int x;
  int y;

  bool operator==(const cell& c) const {
    return x == c.x && y == c.y;
  }

  bool operator!=(const cell& c) const {
    return !(*this == c);
  }
};

int main() {
  int m, n, p, q;
  cell start, dest;
  cin >> m >> n >> p >> q;
  cin >> start.x >> start.y;
  cin >> dest.x >> dest.y;

  vector<cell> res = { dest };
  queue<pair<cell, cell>> open;

  auto board = vector<vector<cell>>(m + 1, vector<cell>(n + 1, { -1, -1 }));

  bool success = false;
  open.push({ start, start });
  while (!open.empty()) {
    auto cur = open.front();
    open.pop();
    cell pos = cur.first;
    cell from = cur.second;

    if (pos.x < 1 || pos.x > m
      || pos.y < 1 || pos.y > n
      || board[pos.x][pos.y] != cell{ -1, -1 }) {
      continue;
    }

    board[pos.x][pos.y] = from;

    if (pos == dest) {
      success = true;
      break;
    }

    open.push({ {pos.x - p, pos.y - q}, pos });
    open.push({ {pos.x - p, pos.y + q}, pos });
    open.push({ {pos.x + p, pos.y - q}, pos });
    open.push({ {pos.x + p, pos.y + q}, pos });

    open.push({ {pos.x - q, pos.y - p}, pos });
    open.push({ {pos.x - q, pos.y + p}, pos });
    open.push({ {pos.x + q, pos.y - p}, pos });
    open.push({ {pos.x + q, pos.y + p}, pos });
  }

  if (!success) {
    cout << -1;
    return 0;
  }

  cell cur = dest;
  do {
    cur = board[cur.x][cur.y];
    res.push_back(cur);
  } while (cur != start);

  reverse(begin(res), end(res));

  cout << res.size() - 1 << endl;
  for (auto& [x, y] : res) {
    cout << x << ' ' << y << endl;
  }
}
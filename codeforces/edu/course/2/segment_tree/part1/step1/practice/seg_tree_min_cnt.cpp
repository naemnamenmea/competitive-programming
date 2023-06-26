#include <iostream>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

//#define LOCAL_LAUNCH
#ifdef LOCAL_LAUNCH
#include <fstream>
#endif

typedef long long ll;

using namespace std;

template<class T>
struct TreeNode
{
  TreeNode(T value) : m_min(value), m_cnt(1) {}
  TreeNode() : m_min(std::numeric_limits<T>::max()), m_cnt(1) {}

  T m_min;
  size_t m_cnt;
};

template<class T>
TreeNode<T> Combine(const TreeNode<T>& leftChild, const TreeNode<T>& rightChild)
{
  TreeNode<T> res;
  if (leftChild.m_min < rightChild.m_min)
  {
    res.m_min = leftChild.m_min;
    res.m_cnt = leftChild.m_cnt;
  }
  else if (leftChild.m_min > rightChild.m_min)
  {
    res.m_min = rightChild.m_min;
    res.m_cnt = rightChild.m_cnt;
  }
  else
  {
    res.m_min = leftChild.m_min;
    res.m_cnt = leftChild.m_cnt + rightChild.m_cnt;
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  ifstream ifs("C:/Users/Andrew/source/repos/C++Workshop/draft/input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  int n, m;
  cin >> n >> m;
  vector<TreeNode<int>> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].m_min;
  }

  SegmentTree<TreeNode<int>> segTree(&Combine<int>);
  segTree.Build(std::move(arr));

  for (int t = 0; t < m; ++t)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      int i, v;
      cin >> i >> v;
      segTree.Set(i, TreeNode<int>(v));
    }
    else if (op == 2)
    {
      int l, r;
      cin >> l >> r;
      auto res = segTree.Calculate(l, r);
      cout << res.m_min << ' ' << res.m_cnt << std::endl;
    }
    else
    {
        throw invalid_argument("wrong operation: " + to_string(op));
    }
  }

  return 0;
}

template<class T>
struct TreeNode
{
  typedef T ValueType;

  operator T() const
  {
    return m_value;
  }

  TreeNode<T> operator +=(T value)
  {
    m_value += value;
    return *this;
  }

  TreeNode(T value) : m_value(value) {}
  TreeNode() : m_value{} {}

  T m_value;
};

template<class T>
TreeNode<T> Combine(const TreeNode<T>& leftChild, const TreeNode<T>& rightChild)
{
  TreeNode<T> res;
  res.m_value = leftChild.m_value + rightChild.m_value;

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

  SegmentTree<TreeNode<ll>> segTree(&Combine<ll>);
  segTree.Init(n);

  for (int t = 0; t < m; ++t)
  {
    int c;
    cin >> c;
    if (c == 1)
    {
      int l, r, v;
      cin >> l >> r >> v;
      segTree.Modify(l, r, v);
    }
    else
    {
      int i;
      cin >> i;
      cout << segTree.Get(i) << std::endl;
    }
  }

  return 0;
}

template<class T>
struct TreeNode
{
  typedef T ValueType;

  TreeNode(T modifyOnSegmentValue)
    : m_modifyOnSegmentValue(modifyOnSegmentValue),
    m_isInitialized(true),
    m_calcOnSegmentValue(modifyOnSegmentValue)
  {}
  TreeNode()
    : m_modifyOnSegmentValue{ 0 },
    m_isInitialized(false),
    m_calcOnSegmentValue(std::numeric_limits<T>::max())
  {}

  T m_calcOnSegmentValue;
  T m_modifyOnSegmentValue;
  bool m_isInitialized;
};

template<class T>
TreeNode<T> Combine(const TreeNode<T>& leftChild, const TreeNode<T>& rightChild)
{
  TreeNode<T> res;
  res.m_calcOnSegmentValue = std::min(leftChild.m_calcOnSegmentValue, rightChild.m_calcOnSegmentValue);

  return res;
}

template<class T>
T Modify(const T& lhs, const T& rhs)
{
  return lhs + rhs;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  ifstream ifs("C:/Users/Andrew/source/repos/C++Workshop/draft/input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  int n, m;
  cin >> n >> m;
  //vector<ll> arr(n);
  //for (int i = 0; i < n; ++i) {
  //  cin >> arr[i];
  //}
  SegmentTree<TreeNode<ll>> segTree(&Combine<ll>, &Modify<ll>);
  segTree.Init(n, 0);
  //segTree.Build(std::move(arr));

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
      int l, r;
      cin >> l >> r;
      cout << segTree.Calculate(l, r).m_calcOnSegmentValue << std::endl;
    }
  }

  return 0;
}


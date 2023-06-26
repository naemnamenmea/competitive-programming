template<class T>
struct TreeNode
{
  typedef T ValueType;

  TreeNode(T calcOnSegmentValue) : m_calcOnSegmentValue(calcOnSegmentValue), m_isInitialized(true) {}
  TreeNode() : m_calcOnSegmentValue{ 0 }, m_isInitialized(false) {}

  T m_applyToSegmentValue;
  T m_calcOnSegmentValue;
  bool m_isInitialized;
};

template<class T>
TreeNode<T> Combine(const TreeNode<T>& leftChild, const TreeNode<T>& rightChild)
{
  TreeNode<T> res;
  res.m_calcOnSegmentValue = leftChild.m_calcOnSegmentValue + rightChild.m_calcOnSegmentValue;
  res.m_isInitialized = true;

  return res;
}

template<class T>
void Modify(TreeNode<T>& node, const T& value)
{
  if (!node.m_isInitialized)
  {
    node.m_calcOnSegmentValue = value;
    node.m_isInitialized = true;
  }
  else
  {
    node.m_calcOnSegmentValue = value;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  ifstream ifs("C:/Users/Andrew/source/repos/C++Workshop/draft/input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  int n, m;
  cin >> n >> m;
  vector<ll> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  SegmentTree<TreeNode<ll>> segTree(&Combine<ll>, &Modify<ll>);
  segTree.Build(std::move(arr));

  for (int t = 0; t < m; ++t)
  {
    int c;
    cin >> c;
    if (c == 1)
    {
      int i, v;
      cin >> i >> v;
      segTree.Set(i, v);
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


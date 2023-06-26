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
    : m_modifyOnSegmentValue(0),
    m_isInitialized(false),
    m_calcOnSegmentValue(((T)1 << 30) - 1)
  {}

  T m_calcOnSegmentValue;
  T m_modifyOnSegmentValue;
  bool m_isInitialized;
};

template<class T>
TreeNode<T> Combine(const TreeNode<T>& leftChild, const TreeNode<T>& rightChild)
{
  TreeNode<T> res;
  res.m_calcOnSegmentValue = leftChild.m_calcOnSegmentValue & rightChild.m_calcOnSegmentValue;

  return res;
}

template<class T>
T Modify(const T& lhs, const T& rhs)
{
  return lhs | rhs;
}

segTree.Build(n, 0);
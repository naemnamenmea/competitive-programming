template<class T>
struct TreeNode
{
  typedef T ValueType;

  TreeNode(T value) : m_value(value), m_isInitialized(true) {}
  TreeNode() : m_value{ std::numeric_limits<int>::max() }, m_isInitialized(false) {}

  T m_value;
  bool m_isInitialized;
};

template<class T>
TreeNode<T> Combine(const TreeNode<T>& leftChild, const TreeNode<T>& rightChild)
{
  TreeNode<T> res;
  res.m_value = std::min(leftChild.m_value, rightChild.m_value);
  res.m_isInitialized = true;

  return res;
}

template<class T>
void Modify(TreeNode<T>& node, const T& value)
{
  if (!node.m_isInitialized)
  {
    node.m_value = value;
    node.m_isInitialized = true;
  }
  else
  {
    node.m_value = std::max(node.m_value, value);
  }
}
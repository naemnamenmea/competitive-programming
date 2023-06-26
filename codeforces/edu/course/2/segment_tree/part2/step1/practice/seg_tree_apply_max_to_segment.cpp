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
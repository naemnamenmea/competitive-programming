struct Node
{
	Node() : Node(0) {}
	Node(const T& value) : m_sum(value) {}
	T m_sum;
};
size_t Find(size_t i) const
{
	return Find(i, 0, 0, m_size);
}
size_t Find(size_t i, size_t x, size_t lx, size_t rx) const
{
	if (lx + 1 == rx)
		return lx;

	size_t m = (lx + rx) / 2;
	if (i < m_tree[x * 2 + 1].m_sum)
	{
		return Find(i, x * 2 + 1, lx, m);
	}
	else
	{
		return Find(i - m_tree[x * 2 + 1].m_sum, x * 2 + 2, m, rx);
	}
}

template<class T>
void Modify(typename SegmentTree<T>::Node& node, const T& value)
{
	node = typename SegmentTree<T>::Node(value);
}

template<class T>
typename SegmentTree<T>::Node Calculate(const typename SegmentTree<T>::Node& lhs, const typename SegmentTree<T>::Node& rhs)
{
	typename SegmentTree<T>::Node res;
	res.m_sum = lhs.m_sum + rhs.m_sum;

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream ifs("input.txt");
	//cin.set_rdbuf(ifs.rdbuf());

	size_t n;
	cin >> n;
	vector<int> p(n);

	for (size_t i = 0; i < n; ++i)
	{
		cin >> p[i];
	}

	vector<int> a(n, 1);
	SegmentTree<int> segTree(&Modify<int>, &Calculate<int>);
	segTree.Build(a);

	vector<int> res(n);
	for (size_t i = 0; i < n; ++i)
	{
		size_t j = n - i - 1;
		size_t idx = segTree.Find(n - i - p[j] - 1);
		res[j] = static_cast<int>(idx + 1);
		segTree.Modify(idx, 0);
	}

	for (size_t i = 0; i < n; ++i)
	{
		cout << res[i] << (i + 1 == n ? "\r\n" : " ");
	}

	return 0;
}
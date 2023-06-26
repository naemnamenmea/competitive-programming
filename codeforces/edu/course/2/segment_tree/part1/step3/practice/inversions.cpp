struct Node
{
	Node() : Node(0) {}
	Node(const T& value) : m_sum(value) {}
	T m_sum;
};
int Find(const T& v, size_t l) const
{
	return Find(v, l, 0, 0, m_size);
}
int Find(const T& v, size_t l, size_t x, size_t lx, size_t rx) const
{
	if (m_tree[x].m_max < v || l >= rx)
		return -1;

	if (lx + 1 == rx)
		return static_cast<int>(lx);

	size_t m = (lx + rx) / 2;
	int res = Find(v, l, x * 2 + 1, lx, m);
	if(res == -1)
	{
		res = Find(v, l, x * 2 + 2, m, rx);
	}
	return res;
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
	vector<int> a(n, 0);

	SegmentTree<int> segTree(&Modify<int>, &Calculate<int>);
	segTree.Build(a);

	for (size_t i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		auto res = segTree.Calculate(v, n);
		cout << res.m_sum << (i + 1 == n ? "\r\n" : " ");
		segTree.Modify(v - 1, 1);
	}

	return 0;
}
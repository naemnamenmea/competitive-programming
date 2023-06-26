struct Node
{
	Node() : Node(0) {}
	Node(const T& value) : m_cnt(value) {}
	T m_cnt;
};
size_t Find(size_t i) const
{
	return Find(i, 0, 0, m_size);
}
size_t Find(size_t k, size_t x, size_t lx, size_t rx) const
{
	if (lx + 1 == rx)
		return lx;

	size_t m = (lx + rx) / 2;
	if (k < m_tree[x * 2 + 1].m_cnt)
	{
		return Find(k, x * 2 + 1, lx, m);
	}
	else
	{
		return Find(k - m_tree[x * 2 + 1].m_cnt, x * 2 + 2, m, rx);
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
	res.m_cnt = lhs.m_cnt + rhs.m_cnt;

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream ifs("input.txt");
	//cin.set_rdbuf(ifs.rdbuf());

	size_t n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (size_t i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	SegmentTree<int> segTree(&Modify<int>, &Calculate<int>);
	segTree.Build(a);

	for (size_t t = 0; t < m; ++t)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			size_t i;
			cin >> i;

			a[i] = 1 - a[i];
			segTree.Modify(i, a[i]);
		}
		else if (op == 2)
		{
			size_t k;
			cin >> k;
			size_t res = segTree.Find(k);
			cout << res << "\r\n";
		}
		else
		{
			throw invalid_argument("wrong operation: " + to_string(op));
		}
	}

	return 0;
}
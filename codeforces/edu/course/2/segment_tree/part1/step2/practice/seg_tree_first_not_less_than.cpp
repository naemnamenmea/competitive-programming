struct Node
{
	Node() : Node(-numeric_limits<T>::max()) {}
	Node(const T& value) : m_max(value) {}
	T m_max;
};

int Find(const T& v, size_t x, size_t lx, size_t rx) const
{
	if (m_tree[x].m_max < v)
		return -1;

	if (lx + 1 == rx)
		return static_cast<int>(lx);

	size_t m = (lx + rx) / 2;
	if (m_tree[x * 2 + 1].m_max >= v)
	{
		return Find(v, x * 2 + 1, lx, m);
	}
	else
	{
		return Find(v, x * 2 + 2, m, rx);
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
	res.m_max = max(lhs.m_max, rhs.m_max);

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
			int value;
			cin >> i >> value;

			segTree.Modify(i, value);
		}
		else if (op == 2)
		{
			int x;
			cin >> x;
			int res = segTree.Find(x);
			cout << res << "\r\n";
		}
		else
		{
			throw invalid_argument("wrong operation: " + to_string(op));
		}
	}

	return 0;
}
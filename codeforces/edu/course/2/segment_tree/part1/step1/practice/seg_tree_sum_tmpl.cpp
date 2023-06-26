struct Node
{
	Node() : m_value(0) {}
	T m_value;
};

template<class T>
void Modify(typename SegmentTree<T>::Node& node, T value)
{
	node.m_value = move(value);
}

template<class T>
T Calculate(const T& lhs, const T& rhs)
{
	return lhs + rhs;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream ifs("input.txt");
	//cin.set_rdbuf(ifs.rdbuf());

	size_t n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (size_t i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	SegmentTree<ll> segTree(&Modify<ll>, &Calculate<ll>);
	segTree.Build(move(a));

	for (size_t t = 0; t < m; ++t)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			size_t i;
			ll value;
			cin >> i >> value;

			segTree.Modify(i, value);
		}
		else if (op == 2)
		{
			size_t l, r;
			cin >> l >> r;
			ll res = segTree.Calculate(l, r);
			cout << res << "\r\n";
		}
		else
		{
			throw invalid_argument("wrong operation: " + to_string(op));
		}
	}

	return 0;
}
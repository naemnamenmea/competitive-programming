struct Node
{
	Node() : Node(0) {}
	Node(const T& value) : m_sum(value) {}
	T m_sum;
};

template<class T>
void Modify(typename SegmentTree<T>::Node& node, const T& value)
{
	node.m_sum += value;
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

	int n, m;
	cin >> n >> m;

	SegmentTree<ll> segTree(&Modify<ll>, &Calculate<ll>);
	segTree.Init(n);

	for (int t = 0; t < m; ++t)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			size_t l, r;
			ll v;
			cin >> l >> r >> v;
			segTree.Modify(l, r, v);
		}
		else if (op == 2)
		{
			size_t i;
			cin >> i;
			ll res = segTree.Get(i).m_sum;
			cout << res << endl;
		}
		else
		{
			throw invalid_argument("wrong operation: " + to_string(op));
		}
	}

	return 0;
}
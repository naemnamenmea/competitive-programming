void Build(const vector<T>& arr, size_t x, size_t lx, size_t rx)
{
	if (lx + 1 == rx) {
		if (rx <= arr.size())
			m_tree[x] = Node(lx, arr[lx]);
		return;
	}

	size_t m = (lx + rx) / 2;

	Build(arr, 2 * x + 1, lx, m);
	Build(arr, 2 * x + 2, m, rx);
	m_tree[x] = m_calculate(m_tree[2 * x + 1], m_tree[2 * x + 2]);
}

struct Node
{
	Node() : Node(0, 0) {}
	Node(size_t i, const T& value) : m_i(i), m_sumEven(i % 2 == 0 ? value : -value), m_sumOdd(i % 2 == 0 ? -value : value) {}
	T m_sumEven;
	T m_sumOdd;
	size_t m_i;
};

template<class T>
void Modify(typename SegmentTree<T>::Node& node, const T& value)
{
	node = typename SegmentTree<T>::Node(node.m_i, value);
}

template<class T>
typename SegmentTree<T>::Node Calculate(const typename SegmentTree<T>::Node& lhs, const typename SegmentTree<T>::Node& rhs)
{
	typename SegmentTree<T>::Node res;
	res.m_sumOdd = lhs.m_sumOdd + rhs.m_sumOdd;
	res.m_sumEven = lhs.m_sumEven + rhs.m_sumEven;

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//ifstream ifs("input.txt");
	//cin.set_rdbuf(ifs.rdbuf());

	int n;
	cin >> n;

	vector<ll> a(n);
	for (size_t i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	SegmentTree<ll> segTree(&Modify<ll>, &Calculate<ll>);
	segTree.Build(a);

	int m;
	cin >> m;
	for (int t = 0; t < m; ++t)
	{
		int op;
		cin >> op;

		if (op == 0)
		{
			size_t i;
			ll value;
			cin >> i >> value;

			segTree.Modify(i - 1, value);
		}
		else if (op == 1)
		{
			size_t l, r;
			cin >> l >> r;
			auto res = segTree.Calculate(l - 1, r);
			cout << ((l - 1) % 2 == 0 ? res.m_sumEven : res.m_sumOdd) << "\r\n";
		}
		else
		{
			throw invalid_argument("wrong operation: " + to_string(op));
		}
	}

	return 0;
}
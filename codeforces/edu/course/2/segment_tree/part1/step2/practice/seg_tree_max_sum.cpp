struct Node
{
	Node() : Node(0) {}
	Node(const T& value) : m_sum(value), m_maxPrefixSum(max(T(0), value)), m_maxSuffixSum(max(T(0), value)), m_maxSum(max(T(0), value)) {}
	T m_sum;
	T m_maxPrefixSum;
	T m_maxSuffixSum;
	T m_maxSum;
};

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
	res.m_maxPrefixSum = max(lhs.m_maxPrefixSum, lhs.m_sum + rhs.m_maxPrefixSum);
	res.m_maxSuffixSum = max(rhs.m_maxSuffixSum, lhs.m_maxSuffixSum + rhs.m_sum);
	res.m_maxSum = (std::max)({ lhs.m_maxSum, rhs.m_maxSum, lhs.m_maxSuffixSum + rhs.m_maxPrefixSum });

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
	vector<ll> a(n);
	for (size_t i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	SegmentTree<ll> segTree(&Modify<ll>, &Calculate<ll>);
	segTree.Build(a);

	auto preRes = segTree.Calculate(0, n);
	cout << preRes.m_maxSum << "\r\n";

	for (size_t t = 0; t < m; ++t)
	{
		size_t i;
		ll value;
		cin >> i >> value;

		segTree.Modify(i, value);
		auto res = segTree.Calculate(0, n);
		cout << res.m_maxSum << "\r\n";
	}

	return 0;
}
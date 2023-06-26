#include "inversions2.cpp"

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

	int n;
	cin >> n;

	SegmentTree<int> segTree(&Modify<int>, &Calculate<int>);
	segTree.Init(2 * n);

	vector<int> p(n, -1);
	vector<int> res(n);
	for (int i = 0; i < 2 * n; ++i)
	{
		int v;
		cin >> v;
		if (p[v - 1] >= 0)
		{
			res[v - 1] = segTree.Calculate(p[v - 1], i).m_sum - 1;
			segTree.Modify(p[v - 1], -1);
		}
		else
		{
			p[v - 1] = i;
		}
		segTree.Modify(i, 1);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << res[i] << (i + 1 == 2 * n ? "\r\n" : " ");
	}

	return 0;
}
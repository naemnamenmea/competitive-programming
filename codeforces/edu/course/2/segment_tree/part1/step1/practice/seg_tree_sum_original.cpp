int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
#ifdef LOCAL_LAUNCH
  ifstream ifs("C:/Users/Andrew/source/repos/C++Workshop/sample/input.txt"); cin.rdbuf(ifs.rdbuf());
#endif
 
  int n, m;
  cin >> n >> m;
  vector<ll> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  SegmentTree<ll> segTree(std::plus<ll>{});
  segTree.Build(std::move(arr));

  for (int t = 0; t < m; ++t)
  {
    int c;
    cin >> c;
    if (c == 1)
    {
      int i, v;
      cin >> i >> v;
      segTree.Set(i, v);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      cout << segTree.ApplyOperation(l, r) << std::endl;
    }
  }
 
  return 0;
}
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define TYPEMIN(type) std::numeric_limits<type>::min()
#define TYPEMAX(type) std::numeric_limits<type>::max()

using namespace std;

const int MAXN = 210 * 1000;
pair<int, int> tree[4 * MAXN];

pair<int, int> get(int node, int node_l, int node_r, int l, int r) {
	if (l <= node_l and node_r <= r) {
		return tree[node];
	} else if (node_r <= l or r <= node_l) {
		return {TYPEMAX(int), TYPEMAX(int)};
	} else {
		int mid = node_l + (node_r - node_l) / 2;
		return min(get(2 * node + 1, node_l, mid, l, r),
			   get(2 * node + 2, mid, node_r, l, r));
	}
}

#define set set_super

pair<int, int> set(int node, int node_l, int node_r, int pos, pair<int, int> val) {
	if (node_l <= pos and pos < node_r) {
		if (node_l == node_r - 1)
			tree[node] = val;
		else {
			int mid = node_l + (node_r - node_l) / 2;
			tree[node] = min(set(2 * node + 1, node_l, mid, pos, val),
					set(2 * node + 2, mid, node_r, pos, val));
		}
	}
	return tree[node];
}

vector<vector<int>> graph;
vector<pair<int, int>> times;
vector<int> depth;
vector<int> sizes;
vector<int> thesad;
#undef set
vector<set<pair<int, int>>> thecount;
#define set set_super

#define time time_super
int n, q, time;

vector<int> order;
int order_t = 0;

void dfs(int v) {
	times[v].first = time++;
	sizes[v] = (graph[v].empty() ? 1 : 0);

	set(0, 0, MAXN, order[v] = order_t++, {depth[v], v});

	for (auto u: graph[v]) {
		depth[u] = depth[v] + 1;
		dfs(u);
		sizes[v] += sizes[u];

		set(0, 0, MAXN, order_t++, {depth[v], v});
	}

	times[v].second = time++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;

#ifndef LOCAL
#define FILE "gangsters"
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
#endif

	std::fill(tree, tree + 4 * MAXN, pair<int, int>{+500500, +500500});

	cin >> n >> q;
	graph.resize(n);
	times.resize(n);
	depth.resize(n);
	sizes.resize(n);
	order.resize(n);
	for (int i = 1; i != n; ++i) {
		int p; cin >> p;
		graph[p - 1].push_back(i);
	}

	time = 0;
	depth[0] = 0;
	dfs(0);

	for (int i = 0; i != n; ++i)
		set(0, 0, MAXN, times[i].first, {depth[i], i});

	int num_pipes = 0, num_sad = 0, num_gang = 0;
	thecount.resize(graph[0].size());
	thesad.resize(graph[0].size());
	for (int i = 0; i != q; ++i) {
		char ch; int v;
		cin >> ch >> v;
		--v;

		auto cmp = [](int v, int u) {return times[v] < times[u];};
		int childid = std::upper_bound(ALL(graph[0]), v, cmp) - graph[0].begin() - 1;
		assert(0 <= childid and childid < (int)graph[0].size());

		num_pipes -= thecount[childid].size() != 0;
		num_sad   -= thesad[childid];

		if (ch == '-')
			thecount[childid].erase({order[v], v});
		else
			thecount[childid].insert({order[v], v});

		if (graph[v].size() == 0)
		{
			if (ch == '-')
				--num_gang;
			else
				++num_gang;
		}

		if (thecount[childid].empty())
			thesad[childid] = 0;
		else {
			pair<int, int> tmp1 = *thecount[childid].begin();
			pair<int, int> tmp2 = *std::prev(thecount[childid].end());

			thesad[childid] = sizes[get(0, 0, MAXN, tmp1.first, tmp2.first + 1).second];
			//cerr << get(0, 0, MAXN, tmp1.first, tmp2.first + 1).second << "!\n";
		}


		num_pipes += thecount[childid].size() != 0;
		num_sad   += thesad[childid];


		cout << num_pipes << " " << num_sad - num_gang << "\n";
	}

	return 0;
}


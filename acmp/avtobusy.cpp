//#define avtobusy
#ifdef avtobusy

#define _USE_MATH_DEFINES
#define INF 2e8

typedef long long ll;

#include <bits/stdc++.h>

using namespace std;

int n;
constexpr int N = 105;
vector<vector<bool>> adj(N, vector<bool>(N, false));
vector<int> prevv(N, -1);
vector<int> dist(N, INF);
vector<bool> used(N, false);
vector<vector<pair<int, int>>> timep(N, vector<pair<int, int>>(N, make_pair(-1, -1)));

int solve(int from, int to) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	dist[from] = 0;
	pq.push(make_pair(dist[from], from));
	used[from] = true;

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		cerr << cur.second << ' ' << cur.first << endl;

		for (int next = 1; next <= n; ++next) {
			if (adj[cur.second][next] &&
				dist[cur.second] <= timep[cur.second][next].first) {

				int val = timep[cur.second][next].second;
				if (!used[next]) {
					used[next] = true;
					dist[next] = val;
					prevv[next] = cur.second;
					pq.push(make_pair(val, next));
				}
				else {
					if (dist[next] > val) {
						dist[next] = val;
						prevv[next] = cur.second;
					}
				}
			}
		}
	}

	return dist[to];
}

int main() {
	//setlocale(LC_ALL, "Russian");
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);

	int k, from, to;
	int left, right, t1, t2;

	cin >> n >> from >> to >> k;
	++n;

	for (int i = 0;i < k;++i) {
		cin >> left >> t1 >> right >> t2;

		adj[left][right] = true;
		timep[left][right] = make_pair(t1, t2);
	}

	int res = solve(from, to);
	if (res == INF) {
		cout << -1 << endl;
	}
	else {
		cout << res << endl;
	}

	for (int i = 1; i < n; ++i) {
		cerr << dist[i] << ' ';
	}

	return 0;
}

#endif //avtobusy
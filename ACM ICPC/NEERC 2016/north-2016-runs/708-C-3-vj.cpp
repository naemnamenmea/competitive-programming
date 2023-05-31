/*#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
*/
#include <bits/stdc++.h>
#define TASK "codecoder"
#define pb push_back
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int MAXN = (int)1e6 + 20;

vector < pii > gg;
int n;
int t[4 * MAXN];

void update(int v, int l, int r, int x, int d) {
	if (r - l == 1) {
		t[v] = d;
		return;
	}
	int mid = l + ((r - l) >> 1);
	if (x < mid)
		update(2 * v + 1, l, mid, x, d);
	else
		update(2 * v + 2, mid, r, x, d);
	t[v] = t[2 * v + 1] + t[2 * v + 2];
}

int get(int v, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr)
		return t[v];
	if (ql >= r || qr <= l)
		return 0;
	int mid = l + ((r - l) >> 1), a, b;
	a = get(2 * v + 1, l, mid, ql, qr);
	b = get(2 * v + 2, mid, r, ql, qr);
	return a + b;
}

int p[MAXN];
bool good[MAXN];

bool cmp(int i, int j) {
	return gg[i].fi < gg[j].fi;
}

vector < vector < int > > qq;

int ans[MAXN];

void solve() {
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		gg.pb({ x, y });
		p[i] = i;
	}
	sort(p, p + n, cmp);
	memset(good, 1, sizeof(good));
	for (int i = 0; i < n; i++) {
		int id = p[i];
		int y = gg[id].second;
		int cc = get(0, 0, MAXN, y + 1, MAXN);
		if (cc)
			good[id] = false;
		update(0, 0, MAXN, y, 1);
	}
	memset(t, 0, sizeof(t));
	for (int i = n - 1; i >= 0; i--) {
		int id = p[i];
		int y = gg[id].second;
		int cc = get(0, 0, MAXN, 0, y);
		if (cc)
			good[id] = false;
		update(0, 0, MAXN, y, 1);
	}
	qq.resize(1);
	vector < int > row;
	for (int i = 0; i < n; i++) {
		int id = p[i];
		if (good[id])
			qq.push_back(row);
		qq.back().push_back(id);
		if (good[id])
			qq.push_back(row);
	}
	int cnt = 0;
	for (int i = 0; i < (int)qq.size(); i++) {
		cnt += qq[i].size();
		for (int j = 0; j < (int)qq[i].size(); j++) {
			int id = qq[i][j];
			ans[id] = cnt - 1;
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	solve();
	return 0;
}
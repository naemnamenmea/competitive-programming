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
int p[MAXN];
int t[4 * MAXN];

void input() {
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		gg.pb({ x, y });
		p[i] = i;
	}
}

void update(int v, int l, int r, int x, int d) {
	if (r - l == 1) {
		t[v] += d;
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

bool cmp(int i, int j) {
	return gg[i] > gg[j]; 
}

int cnt[MAXN];

void solve() {
	fill(cnt, cnt + n, n - 1);
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++) {
		int id = p[i];
		int y = gg[id].se;
		cnt[id] -= get(0, 0, MAXN, y + 1, MAXN);
		update(0, 0, MAXN, y, 1);
	}
	for (int i = 0; i < n; i++)
		cout << cnt[i] << "\n";	
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
	input();
	solve();
	return 0;
}
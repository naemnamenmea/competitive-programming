#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <stdlib.h>
using namespace std;

int ans[100001];
pair<int, int> maxa[100001], maxb[100001];
int ia[100001], ib[100001];
set<int> s;

int main() {
	freopen ("codecoder.in", "r", stdin);
	freopen ("codecoder.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int> > a(n), b(n);
	for (int i = 0; i < n; i++) {
		ans[i] = -1;
		cin >> a[i].first;
		a[i].second = i;
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		ia[a[i].second] = i;
		ib[b[i].second] = i;
	}
	maxa[0].first = ib[a[0].second];
	maxa[0].second = a[0].second;
	for (int i = 1; i < n; i++) {
		if (maxa[i - 1].first > ib[a[i].second]) {
			maxa[i] = maxa[i - 1];
		}
		else {
			maxa[i].first = ib[a[i].second];
			maxa[i].second = a[i].second;
		}
	}
	maxb[0].first = ia[b[0].second];
	maxb[0].second = b[0].second;
	for (int i = 1; i < n; i++) {
		if (maxb[i - 1].first > ia[b[i].second]) {
			maxb[i] = maxb[i - 1];
		}
		else {
			maxb[i].first = ia[b[i].second];
			maxb[i].second = b[i].second;
		}
	}
	int x, cnt = 0;
	while (0) {
		if (a.size() == 0) {
			break;
		}
		if (a[0].second == b[0].second) {
			ans[a[0].second] = cnt;
			cnt++;
			a.erase(a.begin());
			b.erase(b.begin());
		}
		else {
			break;
		}
	}
	int cnt2 = n - 1;
	while (0) {
		if (a[a.size() - 1].second == b[b.size() - 1].second) {
			ans[a[a.size() - 1].second] = cnt2;
			cnt2--;
			a.erase(a.end() - 1);
			b.erase(b.end() - 1);
		}
		else {
			break;
		}
	}
	int tx = 0, ty = 0, tk = 0;
	bool f = true;
	if (a.size() != 0) {
		while (tx < a.size() && ty < a.size()) {
			int x = tx, y = ty, px = -1, py = -1;
			while (1) {
				if (f) {
					y = ib[maxa[x].second];
					f = !f;
					if (y <= py) {
						break;
					}
					py = y;
				}
				else {
					x = ia[maxb[y].second];
					f = !f;
					if (x <= px) {
						break;
					}
					px = x;
				}
			}
			//cout << tx << ' ' << ty << ' ' << px << ' ' << py << '\n';
			s.clear();
			int k;
			for (int i = tx; i <= px; i++) {
				s.insert(a[i].second);
			}
			for (int i = ty; i <= py; i++) {
				s.insert(b[i].second);
			}
		//	cout << s.size() << '\n';
			k = s.size() - 1 + tk;
			for (int i = tx; i <= px; i++) {
				ans[a[i].second] = k;
			}
			for (int i = ty; i <= py; i++) {
				ans[b[i].second] = k;
			}
			tx = px + 1;
			ty = py + 1;
			tk = k + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}

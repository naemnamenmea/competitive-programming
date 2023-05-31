#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int ans[100001];

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
	int x, cnt = 0;
	while (1) {
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
	while (a.size() > 0) {
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
	if (a.size() != 0) {
		for (int i = 0; i < n; i++) {
			if (ans[i] == -1) {
				ans[i] = a.size();
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}

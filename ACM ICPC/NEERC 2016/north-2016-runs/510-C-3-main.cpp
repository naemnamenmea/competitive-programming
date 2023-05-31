#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define pb push_back
#define eb emplace_back

#ifdef local
	#define files
	#define task "file"
#else
	#define files
	#define task "codecoder"
#endif

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

#ifdef files
	freopen(task".in", "r", stdin);	
	freopen(task".out", "w", stdout);	
#endif

	int n; cin >> n;
	vector<int> a(n), b(n), max_r(n);
	vector<pii> sorted_min;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		sorted_min.eb(min(a[i], b[i]), i);
	}                      
	sort(sorted_min.begin(), sorted_min.end());

	for (int i = 0; i < n; i++) {
		int l = i, r = n;
		
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (a[sorted_min[i].second] > a[sorted_min[m].second] || b[sorted_min[i].second] > b[sorted_min[m].second]) {
				l = m;
			} else {
				r = m;
			}
		}

		max_r[i] = l;
	}

	vector<int> max_pref(n, 0);
	for (int i = 0; i < n; i++) {    
		if (i == 0) {
			max_pref[i] = max_r[i];
		} else {
			max_pref[i] = max(max_r[i], max_pref[i-1]);
		}
	}

	vector<int> ans(n, -1);
	for (int i = 0, j = 0; i < n; i++) {
		while (max_pref[j] != j) {
			j = max_pref[j];
		}

		ans[i] = j;
		i = j;
		j++;
	}


	int cur = -1;
	vector<int> rev(n);
	for (int i = 0; i < n; i++) {
		if (ans[i] != -1) {
			cur = ans[i];
		}                               

		rev[sorted_min[i].second] = cur;
	}

	for (int i = 0; i < n; i++) 
		cout << rev[i] << "\n";
	
	return 0;
}
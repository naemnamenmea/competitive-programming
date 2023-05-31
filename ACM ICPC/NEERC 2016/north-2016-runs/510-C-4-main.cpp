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
	vector<int> suf_min_a(n), suf_min_b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		sorted_min.eb(min(a[i], b[i]), i);
	}                      
	
	sort(sorted_min.begin(), sorted_min.end());

	for (int i = n -1; i>= 0; i--) {
		int k = sorted_min[i].second;
		if (i == n-1) {
			suf_min_a[i] = a[k];
			suf_min_b[i] = b[k];
		} else {
			suf_min_a[i] = min(suf_min_a[i+1], a[k]);
			suf_min_b[i] = min(suf_min_b[i+1], b[k]);
		}
	}
                                               

	for (int i = 0; i < n; i++) {
		int l = i, r = n;
		
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (a[sorted_min[i].second] > suf_min_a[m] || b[sorted_min[i].second] > suf_min_b[m]) {
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
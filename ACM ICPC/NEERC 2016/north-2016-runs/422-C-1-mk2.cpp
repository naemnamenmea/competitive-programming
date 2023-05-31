#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 2e5;

int num_cc[N], num_tf[N], cc_num[N], tf_num[N];

int res[N];

pair<pair<int, int>, int> man[N];

int main() {
	ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> man[i].first.first >> man[i].first.second;
		man[i].second = i;
	}
	sort(man, man + n);
	for (int i = 0; i < n; i++) {
		cc_num[i] = man[i].second;
		num_cc[man[i].second] = i;
		swap(man[i].first.first, man[i].first.second);
	}
	sort(man, man + n);
	for (int i = 0; i < n; i++) {
		tf_num[i] = man[i].second;
		num_tf[man[i].second] = i;
	}
	fill(res, res + n, -1);
	int mx = 0;
	for(int i = 0; i < n; i++){
		int man_num_cc = num_cc[tf_num[i]];
		if(man_num_cc > 0){
			mx = max(mx, num_tf[cc_num[man_num_cc - 1]]);
		}
		if(mx <= i){
			for(int j = i; j >= 0 && res[tf_num[j]] == -1; j--){
				res[tf_num[j]] = i;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}

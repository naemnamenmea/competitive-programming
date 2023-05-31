#include <bits/stdc++.h>

using namespace std;


struct str {
	int x, y, i;
	str() {}
	str(int x, int y, int i): x(x), y(y), i(i) {}
	bool operator < (str q) {
		return make_pair(x, y) < make_pair(q.x, q.y);
	}	
};        

vector<int> t;

void build(int l, int r, int pos) {
	if (l == r) {
		t[pos] = 0;
		return;
	}

   	int m = (l + r) / 2;

   build(l, m, pos * 2);
   build(m + 1, r, pos * 2 + 1);

   t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

void update(int l, int r, int lf, int rf, int pos, int val) {
	if (rf < l || r < lf)
		return;

	if (lf <= l && r <= rf) {
		t[pos] = val;
		return;
	}

   	int m = (l + r) / 2;

   	update(l, m, lf, rf, pos * 2, val);
   	update(m + 1, r, lf, rf, pos * 2 + 1, val);
}

int sum(int l, int r, int lf, int rf, int pos) {
	if (rf < l || r < lf)
		return 0;

   	if (lf <= l && r <= rf)
   		return t[pos];
   	
	int m = (l + r) / 2;

   	return sum(l, m, lf, rf, pos * 2) + sum(m + 1, r, lf, rf, pos * 2 + 1);
}

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("codecoder.in", "r", stdin); freopen("codecoder.out", "w", stdout);
	int n;
	cin >> n;
	t.resize(4 * 1e6);
	vector < str > v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
		update(0, 1e6, v[i].y, v[i].y, 1, 1);		
		v[i].i = i;
	}

	build(0, n - 1, 1);

	sort(v.begin(), v.end());
	vector <int> ans(n, 0);
	for(int i = 0; i < n; i++) {
		//cout << v[i].i << ' '  << sum(0, 1e6, 1, v[i].y - 1, 1) << ' ' << i << '\n';
		ans[v[i].i] += sum(0, 1e6, 1, v[i].y - 1, 1);
		update(0, 1e6, v[i].y, v[i].y, 1, 0);		
		ans[v[i].i] += i;
	}
	for(auto i: ans) {
		cout << i << '\n';
	}	
					
    return 0;
}

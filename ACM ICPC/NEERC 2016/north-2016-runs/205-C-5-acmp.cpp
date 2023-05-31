#include<iostream>
#include <algorithm>;
#include <vector>
using namespace std;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	pair<int, int> aa = a.first;
	pair<int, int> bb = b.first;
	if (aa.second < bb.second) return true;
	if (aa.second == bb.second && aa.first < bb.first) return true;
	return false;
}

int main()
{
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n, a, b;
	cin >> n;
	vector<pair<pair<int, int>, int >> v(n);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v[i] = make_pair(make_pair(a, b), i);
	}
	sort(v.begin(), v.end());
	vector<int> d1(n);
	vector<int> d2(n);
	for (int i = 0; i < n-1; i++) {
		if (v[i].first.first < v[i + 1].first.first) d1[v[i+1].second]=d1[v[i].second]+1;
		else d1[v[i + 1].second] = d1[v[i].second];
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n - 1; i++) {
		if (v[i].first.second < v[i + 1].first.second  && v[i].first.first > v[i + 1].first.first){
			d2[v[i + 1].second] = d2[v[i].second] + 1;
		}
//		else d2[v[i + 1].second] = d2[v[i].second];
	}
	for (int i = 0; i < n; i++) {
		cout << d1[i]+d2[i] << endl;
	}
}

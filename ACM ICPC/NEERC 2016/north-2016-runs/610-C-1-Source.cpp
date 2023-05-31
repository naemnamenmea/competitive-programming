#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;

int main() {
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n, i, x, y;
	vector<pair<int, int> > CC;
	vector<pair<int, int> > TF;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> x >> y;
		CC.push_back(make_pair(x, i));
		TF.push_back(make_pair(y, i));
	}
	sort(CC.begin(), CC.end());
	sort(TF.begin(), TF.end());
	vector<int> a(n+1);
	for (i = 0; i < n; i++) {
		a[CC[i].second] = max(a[i], i);
		a[TF[i].second] = max(a[i], i);
	}
	for (i = 1; i <= n; i++)
		cout << a[i] << endl;
	return 0;
}
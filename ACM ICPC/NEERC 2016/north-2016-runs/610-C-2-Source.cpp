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
	vector<int> a(n+1, 0);
	for (i = 1; i < n; i++) {
		if (CC[i].first == CC[i-1].first) 
            a[CC[i].second] = max(a[CC[i-1].second], a[i]);
		else 
            a[CC[i].second] = max(a[i], i);
		if (TF[i].first == TF[i - 1].first)
			a[TF[i].second] = max(a[TF[i - 1].second], a[i]);
		else
			a[TF[i].second] = max(a[i], i);
	}
	for (i = 1; i <= n; i++)
		cout << a[i] << endl;
	return 0;
}
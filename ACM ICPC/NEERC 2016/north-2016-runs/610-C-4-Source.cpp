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
#include <iterator>

using namespace std;

int main() {
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n, i, x, y;
	vector<pair<int, int> > CC;
	vector<pair<int, int> > TF;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		CC.push_back(make_pair(x, i));
		TF.push_back(make_pair(y, i));
	}
	sort(CC.begin(), CC.end());
	sort(TF.begin(), TF.end());
	vector<set<int > > a(n);
	set<int>::iterator iter;
	for (i = 1; i < n; i++) {
		for (iter = a[CC[i - 1].second].begin(); iter != a[CC[i - 1].second].end(); iter++)
			a[CC[i].second].insert(*iter);
		a[CC[i].second].insert(CC[i - 1].second);
		for (iter = a[TF[i - 1].second].begin(); iter != a[TF[i - 1].second].end(); iter++)
			a[TF[i].second].insert(*iter);
		a[TF[i].second].insert(TF[i - 1].second);
	}
	for (i = 0; i < n; i++) {
		if (a[i].find(i) == a[i].end())
			cout << a[i].size() << endl;
		else
			cout << a[i].size() - 1 << endl;
    }
	return 0;
}
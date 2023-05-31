#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define F first
#define S second

typedef long long ll;
//typedef pair<int, int> pii;
//typedef pair<pair<int, int>, int> piii;
using namespace std;

set<int> s;
vector < pair<pair<int, int>, int> > ccs, tfs;

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> res(n);
	for (int i = 0; i < n; i++)
	{
		pair<pair<int, int>, int> t;
		t.second = i;
		cin >> t.F.F >> t.F.S;
		ccs.push_back(t);
		swap(t.F.F, t.F.S);
		tfs.push_back(t);
	}
	sort(ccs.begin(), ccs.end());
	sort(tfs.begin(), tfs.end());
	for (int i = 0; i < n; i++)
	{
		res[ccs[i].S] = i;
	}
	for (int i = 0; i < n; i++)
	{
		res[tfs[i].S] = max(i, res[tfs[i].S]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}
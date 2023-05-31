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
	vector<pair<int, int>> td;
	for (int i = 0; i < n; i++)
	{
		pair<pair<int, int>, int> t;
		t.second = i;
		cin >> t.F.F >> t.F.S;
		ccs.push_back(t);
		//swap(t.F.F, t.F.S);
		//tfs.push_back(t);
	}
	sort(ccs.begin(), ccs.end());
	for (int i = n - 1; i >= 0; i--)
	{
		res[ccs[i].S] = i;
		s.insert(ccs[i].first.second);
		int d = distance(s.begin(), s.find(ccs[i].first.second));
		res[ccs[i].S] += d;
		pair<int, int> tt = make_pair(s.size() - d - 1, ccs[i].S);
		td.push_back(tt);
	}
	for (int i = n - 1; i >= 1; i--)
	{
		if (td[i - 1].F > td[i].F)
		{
			res[td[i - 1].S] += (td[i - 1].F - td[i].F);
			td[i - 1].F = td[i].F;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}
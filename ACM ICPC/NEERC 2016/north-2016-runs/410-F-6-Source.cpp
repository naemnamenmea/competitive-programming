#include <iostream>
#include<stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;

typedef int                            I;
typedef unsigned int                   UI;
typedef long long                      LL;
typedef unsigned long long             ULL;
typedef double                         D;

typedef vector<I>                      VI;
typedef vector<VI>                     VVI;
typedef vector<VVI>                    VVVI;
typedef vector<VVVI>                   VVVVI;

#define F(a,to) for (int a=0; a<(to);++a)
#define Fr(a,from) for (int a=from; a>=0;--a)
#define F(a,from,to) for (int a=from; a<(to);++a)
#define Fr(a,from,to) for (int a=from; a>=to;--a)

bool cmp(pair<int,int>& a, pair<int, int>& b){
	return a.first < b.first;
}

int main(){
	//freopen("put.in", "r", stdin); 
	//freopen("put.out", "w", stdout);
	ios::sync_with_stdio(false);
	freopen("folding.in", "r", stdin); 
	freopen("folding.out", "w", stdout);
	//freopen("codecoder.in", "r", stdin); 
	//freopen("codecoder.out", "w", stdout);

	//int n;
	//cin >> n;
	//vector<pair<int, int>> v1, v2;

	//for (int i = 0; i < n; i++){
	//	int a, b;
	//	cin >> a >> b;
	//	v1[i] = { a, i + 1 };
	//	v2[i] = { b, i + 1 };
	//}

	//sort(v1.begin(), v1.end(), &cmp);
	//sort(v2.begin(), v2.end(), &cmp);

	//map<int, int> mp;

	//for (int i = 0; i < n; i++){
	//	mp[v1[i].second] = max(mp[v1[i].second], v1[i].first);
	//	mp[v2[i].second] = max(mp[v2[i].second], v2[i].first);
	//}

	//for (auto& a : mp){
	//	cout << a.second << '\n';
	//}

	//return 0;

	D a1[2], a2[2];

	cin >> a1[0] >> a1[1] >> a2[0] >> a2[1];

	if (a1[0] < a1[1]) swap(a1[0], a1[1]);
	if (a2[0] < a2[1]) swap(a2[0], a2[1]);

	if (a2[0] > a1[0] || a2[1] > a1[1])
	{
		cout << -1;
		return 0;
	}

	int cnt1 = 10e8;
	if (a1[1] == a2[0])
	{
		cnt1 = 0;
		D aa = a1[0];
		while (aa > a2[1])
		{
			aa = aa / 2.;
			++cnt1;
		}
	}

	int cnt = 0;

	while (a1[0] > a2[0])
	{
		a1[0] = a1[0] / 2.;
		++cnt;
	}

	while (a1[1] > a2[1])
	{
		a1[1] = a1[1] / 2.;
		++cnt;
	}

	cout << min (cnt, cnt1);

	return 0;
}
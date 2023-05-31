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

bool flagGG = false;
bool flagVP = false;

struct coder
{
	int num, c, t;
	bool flag = false;


	bool operator< (const coder& cod1) const
	{
		if (flagGG)
		{
			return num < cod1.num;
			if (c != cod1.c) return c < cod1.c;
			return t < cod1.t;
		}

		if (flag)
		{
			if (c != cod1.c) return c < cod1.c;

		}
		else
		{
			if (t != cod1.t) return t < cod1.t;
		}

		return num < cod1.num;
	}

	bool operator== (const coder& cod1)const
	{
		if (flagVP)return c == cod1.c;
		return t == cod1.t;
	}

};

int main(){
	//freopen("put.in", "r", stdin); 
	//freopen("put.out", "w", stdout);
	ios::sync_with_stdio(false);
	freopen("codecoder.in", "r", stdin); 
	freopen("codecoder.out", "w", stdout);
	
	int n;
	cin >> n;
	vector<coder> a;

	set <coder> s1, s2;

	F(i, n)
	{
		coder t;
		cin >> t.c >> t.t;
		t.num = i;

		a.push_back(t);

		s1.insert(t);
		t.flag = true;
		s2.insert(t);
	}

	F(i, n)
	{
		set <coder> ans;

		auto itt = s1.find(a[i]);
		auto itt2 = itt;

		flagGG = true;
		flagVP = false;
		while (itt2 != s1.begin() && *(--itt2) == *itt)
		{
			--itt;
		};
		ans.insert(s1.begin(), itt);
		//if (ans.size() && *(--ans.end()) == a[i]) ans.erase(--ans.end());
		flagGG = false;

		a[i].flag = true;
		auto it = s2.find(a[i]);
		auto it2 = it;

		flagGG = true;
		flagVP = true;
		while (it2 != s2.begin() && *(--it2) == *it)
		{
			--it;
		}
		ans.insert(s2.begin(), it);
		//if (ans.size() && *(--ans.end()) == a[i]) ans.erase(--ans.end());
		flagGG = false;

		cout << ans.size() << "\n";
	}

	return 0;

	//int n;
	//cin >> n;
	//vector<pair<int, int>> v1(n), v2(n);

	//for (int i = 0; i < n; i++){
	//	int a, b;
	//	cin >> a >> b;
	//	v1[i] = { a, i + 1 };
	//	v2[i] = { b, i + 1 };
	//}

	//sort(v1.begin(), v1.end(), &cmp);
	//sort(v2.begin(), v2.end(), &cmp);

	//map<int, int> mp;

	//int l = 0;
	//for (int i = 0; i < n; i++){
	//	if (i && v1[i - 1].first == v1[i].first){
	//		mp[v1[i].second] = max(mp[v1[i].second], l);
	//	}
	//	else{
	//		mp[v1[i].second] = max(mp[v1[i].second], i);
	//		l = i;
	//	}
	//}

	//l = 0;
	//for (int i = 0; i < n; i++){
	//	if (i && v2[i - 1].first == v2[i].first){
	//		mp[v2[i].second] = max(mp[v2[i].second], l);
	//	}
	//	else{
	//		mp[v2[i].second] = max(mp[v2[i].second], i);
	//		l = i;
	//	}
	//}

	//for (auto& a : mp){
	//	cout << a.second << '\n';
	//}

	//return 0;
}
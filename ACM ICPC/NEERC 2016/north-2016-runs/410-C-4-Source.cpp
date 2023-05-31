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

struct coder
{
	int num, c, t;
	bool flag = false;


	bool operator< (const coder& cod1) const
	{
		if (flagGG)
		{
			return num < cod1.num;
		}

		if (flag)
		{
			return c < cod1.c;
		}
		else
		{
			return t < cod1.t;
		}

		return num < cod1.num;
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

		flagGG = true;
		ans.insert(s1.begin(), itt);
		flagGG = false;

		a[i].flag = true;
		auto it = s2.find(a[i]);

		flagGG = true;
		ans.insert(s2.begin(), it);
		flagGG = false;

		cout << ans.size() << "\n";
	}

	return 0;
}
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

int main(){
	freopen("put.in", "r", stdin); 
	freopen("put.out", "w", stdout);
	//freopen("folding.in", "r", stdin); 
	//freopen("folding.out", "w", stdout);

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
		int aa = a1[0];
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
#include <iostream>
#include<stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <sstream>
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
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);

	I a1[2], a2[2];

	cin >> a1[0] >> a1[1] >> a2[0] >> a2[1];

	if (a1[0] < a1[1]) swap(a1[0], a1[1]);
	if (a2[0] < a2[1]) swap(a2[0], a2[1]);

	if (a2[0] > a1[0] || a2[1] > a1[1])
	{
		cout << -1;
		return 0;
	}

	int cnt = 0;

	while (a1[0] > a2[0])
	{
		a1[0] = ceil(double (a1[0]) / 2);
		++cnt;
	}

	while (a1[1] > a2[1])
	{
		a1[1] = ceil(double(a1[1]) / 2);
		++cnt;
	}

	cout << cnt;

	return 0;
}
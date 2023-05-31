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

int mind = -1, minm = -1, miny = -1;

bool set_min(int d, int m, int y){
	bool res = false;

	if (y > miny){
		miny = y, minm = m, mind = d;
		res = true;
	}
	else if (y == miny){
		if (m > minm){
			minm = m, mind = d;
			res = true;
		}
		else if (m == minm){
			if (d > mind){
				mind = d;
				res = true;
			}
		}
	}

	return res;
}

int main(){
	//freopen("put.in", "r", stdin); 
	//freopen("put.out", "w", stdout);
	freopen("folding.in", "r", stdin); 
	freopen("folding.out", "w", stdout);
	//freopen("king.in", "r", stdin); \
	//freopen("king.out", "w", stdout);

	//int kd, km, ky;
	//cin >> kd >> km >> ky;

	//int n;
	//cin >> n;

	//int res = -1;
	//

	//for (int i = 0; i < n; i++){
	//	int d, m, y;
	//	cin >> d >> m >> y;

	//	if (ky - y > 18){
	//		if (set_min(d, m, y)) res = i + 1;
	//	}
	//	else if (ky - y == 18){
	//		if (km >= m && kd >= d){
	//			if (set_min(d, m, y)) res = i + 1;
	//		}
	//	}
	//}

	//cout << res;

	//return 0;
	I a1[2], a2[2];

	cin >> a1[0] >> a1[1] >> a2[0] >> a2[1];

	if (a1[0] < a1[1]) swap(a1[0], a1[1]);
	if (a2[0] < a2[1]) swap(a2[0], a2[1]);

	if (a2[0] > a1[0] || a2[1] > a1[1])
	{
		cout << -1;
		return 0;
	}

	if (a1[1] == a2[0] && a1[0] >= a2[1])
	{
		int cnt = 0;

		while (a1[0] > a2[1])
		{
			a1[0] = ceil(double(a1[0]) / 2);
			++cnt;
		}

		cout << cnt;
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
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
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);

	I n[2], a1[2], a2[2];

	cin >> n[0] >> n[1] >> a1[0] >> a1[1] >> a2[0] >> a2[1];

	if (a1[0] == a2[0])
	{
			cout << 0 << " " << a1[1] << " " << n[0] << " " << a2[1];
			return 0;
	}

	cout << a1[0] << " " << n[1] << " " << a2[0] << " " << 0;

	return 0;
}
#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>

using namespace std;
typedef long long ll;

int main(){
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	ll w, h, ax, ay, bx, by;
	cin >> w >> h >> ax >> ay >> bx >> by;
	if (ax != bx)
	{
		cout << ax << ' ' << 0 << ' ' << bx << ' ' << h;
	}
	else
		cout << 0 << ' ' << ay << ' ' << w << ' ' << by;
	return 0;
}


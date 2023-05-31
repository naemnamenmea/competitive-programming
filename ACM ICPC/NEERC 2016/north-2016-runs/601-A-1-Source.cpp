#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int ax,  ay, bx,  by, w, h;
int main(){
	freopen("anniversary.in","r",stdin);
	freopen("anniversary.out","w",stdout);
	cin >> w >> h >> ax >> ay >> bx>> by;
	if (ax == bx) cout << 0 << ' ' << ay << ' ' << w << ' ' << by; else
		cout << ax << ' ' << 0 << ' ' << bx << ' ' << h;
	return 0;
}
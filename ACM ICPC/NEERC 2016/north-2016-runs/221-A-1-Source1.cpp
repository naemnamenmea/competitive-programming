#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	int w, h;
	cin >> w >> h;
	int ax, ay, bx, by;
	cin >> ax >> bx >> ay >> by;
	if (ax != ay)
		cout << ax << " 0 " << ay << " " << h << endl;
	else
		cout << "0 " << bx << " " << w << " " << by << endl;
	return 0;
}
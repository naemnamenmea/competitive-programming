#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	int x, y;
	int w, h;
	int cx, cy;
	int s1 = 0, s2 = 0;
	cin >> x >> y >> w >> h;
	cx = x;
	cy = y;
	if ((x < w || y < h) && (cx < h || cy < w)) {
		cout << -1;
		return 0;
	}
	while (x > w) {
		x /= 2;
		s1++;
	}
	while (y > h) {
		y /= 2;
		s1++;
	}
	while (cx > h) {
		cx /= 2;
		s2++;
	}
	while (cy > w) {
		cy /= 2;
		s2++;
	}
	cout << min(s1, s2);
	return 0;
}
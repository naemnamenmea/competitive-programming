#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("anniversary.in","r",stdin);
	freopen("anniversary.out","w",stdout);
	int w, h;
	cin >> w >> h;
	int x, y;
	cin >> x >> y;
	int xx, yy;
	cin >> xx >> yy;
	if (x == xx) {
		cout << "0 " << y << " " << w << " " << yy << endl;
		return 0;
	}            else {
		cout << x << " 0 " << xx << " " << h << endl;
		}
	return 0;
}

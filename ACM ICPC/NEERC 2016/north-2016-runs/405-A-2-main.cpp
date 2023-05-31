#include <bits/stdc++.h>

using namespace std;
                   
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int main () {                   
	freopen ("anniversary.in", "r", stdin);
	freopen ("anniversary.out", "w", stdout);
	int w, h, x1, y1, x2, y2;
	cin >> w >> h >> x1 >> y1 >> x2 >> y2;
	if (x1 != x2) {
		cout << x1 << " " << 0 << " " << x2 << " " << h << endl;
	} else {
		cout << 0 << " " << y1 << " " << w << " " << y2 << endl;
	} 

	return 0;
}
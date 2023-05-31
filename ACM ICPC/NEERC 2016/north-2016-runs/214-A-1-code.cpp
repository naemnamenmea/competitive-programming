#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <assert.h>
#include <memory>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ll long long 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	freopen("anniversary.in", "rt", stdin);
	freopen("anniversary.out", "wt", stdout);

	int w, h, ax, ay, bx, by;
	cin >> w >> h >> ax >> ay >> bx >> by;

	if (ax == bx) {
		cout << 0 << " " << ay << " " << w << " " << by << endl;
	}
	else {
		cout << ax << " " << 0 << " " << bx << " " << h << endl;
	}

	return 0;
}
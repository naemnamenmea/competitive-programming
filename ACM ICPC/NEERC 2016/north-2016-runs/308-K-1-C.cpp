#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>


typedef long long ll;
using namespace std;

#define mp(x, y)  std::make_pair(x, y)
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

inline ll epoch(ll d, ll m, ll y) {
	
	ll total = y * 365 + d;
	for (int i = 1; i <= m; ++i) {
		if (i == 1) total += 31;
		if (i == 2) total += 28;
		if (i == 3) total += 31;
		if (i == 4) total += 30;
		if (i == 5) total += 31;
		if (i == 6) total += 30;
		if (i == 7) total += 31;
		if (i == 8) total += 31;
		if (i == 9) total += 30;
		if (i == 10) total += 31;
		if (i == 11) total += 30;
		if (i == 12) total += 31;
	}

	return total;
}


int main(){
	assert(freopen("king.in", "r", stdin));
	assert(freopen("king.out", "w+", stdout));
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	ll kd, km, ky;
	cin >> kd >> km >> ky;

	ll death = epoch(kd, km, ky);

	int n;
	cin >> n;

	int current = 0;
	int current_epoch = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> kd >> km >> ky;
		ll cur = epoch(kd, km, ky);
		if (cur > current_epoch && (death - cur) / 365 >= 18) {
			current = i;
			current_epoch = cur;
		}

		//cout << (death - cur) / 365 << endl;

	}

	if (current == 0) cout << -1 << endl;
	else cout << current << endl;

	return 0;
}
	
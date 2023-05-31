#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ll long long 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back

ll x[200200];
ll y[200200];

ll sum[200200];

ll wtfsum[2][2][2];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	freopen("integral.in", "rt", stdin);
	freopen("integral.out", "wt", stdout);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &x[i], &y[i]);
		x[i] += 1000000000LL;
		y[i] += 1000000000LL;
	}

	x[n] = x[0], y[n] = y[0];


	ll S = 0;
	for (int i = 0; i < n; i++) {
		S += (x[i + 1] - x[i]) * (y[i + 1] + y[i]);
	}
	S = abs(S);
	if (S % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}

	sum[0] = 0;
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		ll dx = x[i + 1] - x[i];
		ll dy = y[i + 1] + y[i];
		ll wtf = dx * dy % 2LL;
		cur = (cur + wtf) % 2;
		sum[(i + 1) % n] = cur;
	}

	for (int i = 0; i < n; i++) {
		wtfsum[x[i] % 2][y[i] % 2][sum[i]]++;
	}


	ll res = 0;


	for (int i = 0; i < n; i++) {
		ll curx = x[i] % 2;
		ll cury = y[i] % 2;
		ll cursum = sum[i] % 2;
		res += wtfsum[curx][cury][cursum] + wtfsum[curx][!cury][cursum] + wtfsum[!curx][cury][cursum] - 1;
		res += wtfsum[!curx][!cury][!cursum];
		res -= 2;
	}
	cout << res / 2LL << endl;

	return 0;
}
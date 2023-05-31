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

int solve(int a, int b, int c, int d) {
	int res = 0;
	if (a < c || b < d) return 1e9;
	while (a > c) {
		a = (a + 1) / 2;
		res++;
	}
	while (b > d) {
		b = (b + 1) / 2;
		res++;
	}
	return res;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	freopen("folding.in", "rt", stdin);
	freopen("folding.out", "wt", stdout);

	int a, b;
	int c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int res = min(solve(a, b, c, d), solve(a, b, d, c));
	if (res == 1e9) res = -1;
	cout << res << endl;

	return 0;
}
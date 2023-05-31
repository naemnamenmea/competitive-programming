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
	freopen("folding.in", "rt", stdin);
	freopen("folding.out", "wt", stdout);

	int a, b;
	int c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (a < b) swap(a, b);
	if (c < d) swap(c, d);
	if (c > a || d > b) {
		cout << "-1" << endl;
		return 0;
	}
	int res = 0;
	while (a > c) {
		a = (a + 1) / 2;
		res++;
	}
	while (b > d) {
		b = (b + 1) / 2;
		res++;
	}
	printf("%d", res);

	return 0;
}
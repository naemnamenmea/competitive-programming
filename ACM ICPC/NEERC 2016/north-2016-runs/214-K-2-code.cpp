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
	freopen("king.in", "rt", stdin);
	freopen("king.out", "wt", stdout);

	int d, m, y;
	scanf("%d %d %d", &d, &m, &y);
	int n;
	scanf("%d", &n);
	int idx = -1;
	int besty = -1, bestm = -1, bestd = -1;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (y - c > 18 || y - c == 18 && (b < m || b == m && a <= d)) {
			if (idx == -1 || c > besty || c == besty && (b > bestm || (b == bestm && a > bestd))) {
				idx = i;
				besty = c;
				bestm = b;
				bestd = a;
			}
		}
	}
	printf("%d", idx);

	return 0;
}
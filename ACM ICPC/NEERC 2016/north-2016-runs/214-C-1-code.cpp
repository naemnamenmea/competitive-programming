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

bool used[100100];
int X[100100];
int Y[100100];
set<pair<int, int> > x;
set<pair<int, int> > y;
int ans[100100];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	freopen("codecoder.in", "rt", stdin);
	freopen("codecoder.out", "wt", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		X[i] = a;
		Y[i] = b;
		x.insert(mp(a, i));
		y.insert(mp(b, i));
	}

	int ost = n;
	while (sz(x) > 0) {
		ost = sz(x);
		priority_queue<pair<int, int> > qx;
		priority_queue<pair<int, int> > qy;
		int id = (--x.end())->second;
		used[id] = true;
		x.erase(mp(X[id], id));
		y.erase(mp(Y[id], id));
		ans[id] = ost - 1;
		qx.push(mp(X[id], id));
		qy.push(mp(Y[id], id));
		while (!qx.empty() || !qy.empty()) {
			while (!qx.empty()) {
				int id = qx.top().second;
				qx.pop();
				while (y.upper_bound(mp(Y[id], -1)) != y.end()) {
					int idx = y.upper_bound(mp(Y[id], -1))->second;
					used[idx] = true;
					x.erase(mp(X[idx], idx));
					y.erase(mp(Y[idx], idx));
					qx.push(mp(X[idx], idx));
					qy.push(mp(Y[idx], idx));
					ans[idx] = ost - 1;
				}
			}
			while (!qy.empty()) {
				int id = qy.top().second;
				qy.pop();
				while (x.upper_bound(mp(X[id], -1)) != x.end()) {
					int idx = x.upper_bound(mp(X[id], -1))->second;
					used[idx] = true;
					x.erase(mp(X[idx], idx));
					y.erase(mp(Y[idx], idx));
					qx.push(mp(X[idx], idx));
					qy.push(mp(Y[idx], idx));
					ans[idx] = ost - 1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);


	return 0;
}
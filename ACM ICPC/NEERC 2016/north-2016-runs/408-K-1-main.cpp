#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define TYPEMIN(type) std::numeric_limits<type>::min()
#define TYPEMAX(type) std::numeric_limits<type>::max()

using namespace std;

const int MAXN = 100500;

int D, M, Y;
int n;
int d[MAXN], m[MAXN], y[MAXN];

bool check(int i) {
	int age = Y - y[i];
	if (age == 18)
		age -= !(m[i] < M || (m[i] == M && d[i] <= D));
	return age >= 18;
}

bool better(int i, int j) {
	return y[i] > y[j] || (y[i] == y[j] && m[i] > m[j]) || (y[i] == y[j] && m[i] == m[j] && d[i] > d[j]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;

#ifndef LOCAL
#define FILE "king"
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
#endif

	cin >> D >> M >> Y;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> d[i] >> m[i] >> y[i];

	int best = -1;
	for (int i = 0; i < n; i++) {
		if (check(i)) {
			best = i;
			//cerr << i << '\n';
		}
	}

	if (best == -1) {
		cout << -1;
		exit(0);
	}

	for (int i = 0; i < n; i++)
		if (check(i) && better(i, best))
			best = i;
	cout << best + 1;

	return 0;
}


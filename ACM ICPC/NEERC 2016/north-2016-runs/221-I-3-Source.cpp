#pragma comment(linker, "/STACK:100000000")

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define mp make_pair
#define fi(a, b) for (int i = a; i <= b; ++i)
#define fj(a, b) for (int j = a; j <= b; ++j)
#define sqr(x) (x) * (x - 1) / 2

typedef pair<long long, long long> pi;

long long operator %(pi p1, pi p2) {
	return p1.first * p2.second - p2.first * p1.second;
}

long long a[2][2], b[2][2];

int main(){
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	freopen("integral.in", "r", stdin);
	freopen("integral.out", "w", stdout);
#endif
	
	long long n, x, y;

	cin >> n;
	vector<pi> v, v0, v1;

	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		v.push_back(mp(abs(x % 2), abs(y % 2)));
	}

	long long ans = 0, p = 0;

	v0.push_back(v[0]);
	a[v[0].first][v[0].second]++;
	for (int i = 1; i < n; ++i) {
		p += v[i - 1] % v[i];
		if (p % 2 == 0) {
			v0.push_back(v[i]);
			a[v[i].first][v[i].second]++;
		}
		else {
			v1.push_back(v[i]);
			b[v[i].first][v[i].second]++;
		}
	}

	p += v[0] % v[n - 1];

	if (p % 2 == 1) {
		cout << 0;
		return 0;
	}

	fi(0, 1)
		fj(0, 1)
		    ans += sqr(a[i][j]) + sqr(b[i][j]);

	ans += a[0][0] * (a[0][1] + a[1][0] + a[1][1]);
	ans += b[0][0] * (b[0][1] + b[1][0] + b[1][1]);

	ans += a[1][1] * (b[1][0] + b[0][1]);
	ans += a[0][1] * (b[1][1] + b[1][0]);
	ans += a[1][0] * (b[0][1] + b[1][1]);
    
	cout << ans - n;

	return 0;
}
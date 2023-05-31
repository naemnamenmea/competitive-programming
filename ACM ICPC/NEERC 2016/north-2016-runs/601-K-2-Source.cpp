#include<iostream>
#include<cstdio>
#include<algorithm>
#define y1 stupedcmath
using namespace std;
int i, d, m, y, n, j = 0, d1, m1, y1, m2, y2 = 0, d2;

int main(){
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	cin >> d >> m >> y >> n;
	for (i = 0; i < n; i++){
		cin >> d1 >> m1 >> y1;
		if (y1 + 18 < y || (y1 + 18 == y && m1 < m) || (y1 + 18 == y && m1 == m && d1 <= d))
			if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)) d2 = d1, y2 = y1, m2 = m1, j = i + 1;
	}
	if (j == 0) cout << -1; else cout << j;
	//cout << d2 << ' ' << m2 << ' ' << y2;
	return 0;
}
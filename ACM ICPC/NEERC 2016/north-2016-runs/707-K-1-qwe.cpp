#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<map>
#include<string>
#include<queue>
#define ll long long int
using namespace std;

void sol(){
	int d, m, y;
	cin >> d >> m >> y;
	int n;
	cin >> n;
	int sum = -2;
	vector < pair<pair<int, int>, pair<int, int> > > g(n);
	for(int i = 0; i < n; i++) {
		int dd, mm, yy;
		cin >> dd >> mm >> yy;
		g[i] = make_pair(make_pair(yy, mm), make_pair(dd, i));
	}
	sort(g.begin(), g.end());
	for(int i = 0 ; i < n; i++) {
		int dd = g[i].second.first;
			int mm = g[i].first.second;
			int yy = g[i].first.first;
			int j = g[i].second.second;
		if(y - yy > 18) {
			sum = j;
			//cout << dd << " " << mm << " " << yy;
		}else if( y - yy == 18) {
			if(m > mm) {
				sum = j;
				//cout << dd << " " << mm << " " << yy;
				continue;
			} else if( m == mm) {
				if( d >= dd) {
					sum = j;
					//cout << dd << " " << mm << " " << yy;
				}
			}
		}
	}
		cout << sum + 1;
}


int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
#endif
	sol();
}
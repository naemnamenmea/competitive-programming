/*#include <fstream>

int main(){
	std::ifstream IF("folding.in");
	std::ofstream OF("folding.out");
	int H, h, W, w;
	IF >> W >> H >> w >> h;
	if (w > W || h > H){
		if (h <= W && w <= H){
			int temp = h;
			h = w;
			w = temp;
			goto _allright;
		}
		OF << -1; return 0;
	}
	_allright:
	int counter = 0;
	while (W > w * 2){
		W += W & 1;
		W >>= 1;
		counter++;
	}
	while (H > h * 2){
		H += H & 1;
		H >>= 1;
		counter++;
	}
	if (W > w){
		counter++;
	}
	if (H > h){
		counter++;
	}
	OF << counter;
	return 0;
}*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#define y1 stupedcmath
using namespace std;
int i,d,m,y,n,j=0,d1,m1,y1,m2,y2=0,d2;

int main(){
	freopen("king.in","r",stdin);
	freopen("king.out","w",stdout);
	cin >> d >> m >> y>>n;
	for (i = 0; i < n; i++){
		cin >> d1 >> m1 >> y1;
		if (y1 + 18 < y || (y1 + 18 == y && m1 < m) || (y1 + 18 == y && m1 == m && d1 <= d))
			if (y1 > y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 < d2)) d2 = d1, y2 = y1, m2 = m1, j = i + 1;
	}
	if (j == 0) cout << -1; else cout << j;
	//cout << d2 << ' ' << m2 << ' ' << y2;
	return 0;
}
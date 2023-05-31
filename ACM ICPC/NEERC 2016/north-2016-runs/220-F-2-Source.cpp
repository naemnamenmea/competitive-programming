//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	freopen("folding.in", "r", stdin);
//	//freopen("folding.out", "w", stdout);
//	
//	int Y, M, D;
//	int y, m, d;
//	int number;
//	y = 10002;
//	m = 13;
//	d = 32;
//	int mas[105][3] = {};
//	cin >> D >> M >> Y;
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> mas[i][0] >> mas[i][1] >> mas[i][2];
//		if ((Y - mas[i][2] > 18)
//			|| ((Y - mas[i][2] == 18) && (mas[i][1] < M))
//			|| ((Y - mas[i][2] == 18) && (mas[i][1] == M) && (mas[i][0] <= D)))
//		{
//			if (mas[i][2] < y)
//			{
//				y = mas[i][2];
//				d = mas[i][0];
//				m = mas[i][1];
//				number = i;
//				continue;
//			}
//			if (mas[i][2] == y)
//			{
//				if (mas[i][1] < m)
//				{
//					y = mas[i][2];
//					d = mas[i][0];
//					m = mas[i][1];
//					number = i;
//					continue;
//				}
//				if (mas[i][1] == m)
//				{
//					if (mas[i][0] < d)
//					{
//						y = mas[i][2];
//						d = mas[i][0];
//						m = mas[i][1];
//						number = i;
//						continue;
//					}
//
//				}
//			}
//
//		}
//	}
//
//
//
//if (y == 10002)
//{
//	cout << "-1";
//}
//else
//{
//	cout << number;
//}
//
//
//
//
//return 0;
//}
#include<stdio.h>
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int main(){
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);


	int W;
	int H;
	int w, h;
	cin >> W >> H >> w >> h;
	int count = 0;
	int count2 = 0;
	int w2 = h;
	int h2 = w;
	if (w > W || h > H){
		swap(w, h);
		if (w > W || h > H){
			cout << "-1";
			return 0;
		}
	}
	while (W > w){
		w *= 2;
		count++;
	}
	while (H > h){
		h *= 2;
		count++;
	}

	if (w2 > W || h2 > H){
		cout << count;
		return 0;
	}

	while (W > w2){
		w2 *= 2;
		count2++;
	}
	while (H > h2){
		h2 *= 2;
		count2++;
	}
	cout << min(count, count2);


	return 0;
}
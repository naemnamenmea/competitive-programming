#include<stdio.h>
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	int W;
	int H;
	int w, h;
	cin >> W >> H >> w >> h;
	int count = 0;
	int count2 = 0;
	int w2 = w;
	int h2 = h;
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
	swap(w, h);
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
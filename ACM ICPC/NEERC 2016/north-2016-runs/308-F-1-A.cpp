#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define mp(x, y)  std::make_pair(x, y)
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main(){
	assert(freopen("folding.in", "r", stdin));
	assert(freopen("folding.out", "w+", stdout));
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);


	int W, H;
	int w, h;

	std::cin >> W >> H >> w >> h;
	bool bad1 = ((W < w) || (H < h));
	bool bad2 = ((W < h) || (H < w));
	if (bad1 && bad2){
		std::cout << -1;
		return 0;
	}

	

	double eps = 1E-6;
	pair<double, double> current1 = mp((double)W, (double)H);
	pair<double, double> current2 = mp((double)H, (double)W);
	int count1 = 0;
	int count2 = 0;
	while (true) {
		if (fabs(current1.first - w) > eps){
			current1 = mp(current1.first / 2.0, current1.second);
			++count1;
			if (current1.first < w){
				current1.first = w;
			}
		}
		else if (fabs(current2.first - w) > eps){
			current2 = mp(current2.first / 2.0, current2.second);
			++count2;
			if (current2.first < w){
				current2.first = w;
			}
		}
		else{
			break;
		}
	}

	while (true) {
		if (fabs(current1.second - h) > eps){
			auto second1 = mp(current1.first, current1.second / 2.0);
			++count1;
			if (second1.second < h){
				second1.second = h;
			}
			current1 = second1;
		}
		else if (fabs(current2.second - h) > eps){
			auto second2 = mp(current2.first, current2.second /2.0);
			++count2;
			if (second2.second < h){
				second2.second = h;
			}
			current2 = second2;
		}
		else{
			break;
		}
	}
	if (bad1){
		std::cout << count2;
	}
	else if (bad2){
		std::cout << count1;
	}
	else{
		std::cout << MIN(count1, count2);
	}
	return 0;
}

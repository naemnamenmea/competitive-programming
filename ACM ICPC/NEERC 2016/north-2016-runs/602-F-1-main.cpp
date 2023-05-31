#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>

using namespace std;

struct kid{
	int d;
	int m;
	int y;
};

void main(){
	ifstream in("folding.in");
	ofstream out("folding.out");
	double W, H, w, h,Wtmp,Htmp;
	int count1 = 0,count2=0;
	in >> W >> H >> w >> h;
	if (h > W || w > H)
		count2 = -1;
	else{
		Wtmp = W;
		Htmp = H;
		while (Wtmp > h){
			Wtmp /= 2;
			count2++;
		}
		while (Htmp > w){
			Htmp /= 2;
			count2++;
		}
	}

	if (w > W || h > H)
		count1 = -1;
	else{
		Wtmp = W;
		Htmp = H;
		while (Wtmp > w){
			Wtmp /= 2;
			count1++;
		}
		while (Htmp > h){
			Htmp /= 2;
			count1++;
		}
	}

	if (count1 != -1){
		if (count2 != -1){
			if (count1 > count2)
				count1 = count2;
		}
	}
	else if (count2 != -1) count1 = count2;

	out << count1;
}
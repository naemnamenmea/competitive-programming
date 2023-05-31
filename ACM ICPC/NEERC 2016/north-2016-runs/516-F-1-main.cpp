#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

struct mymm{
	long long x, y;
};

		
	ifstream in("folding.in");
	ofstream out("folding.out");

	int main(){

		long long W, H, w, h,huy,WW,HH;
		in >> W >> H >> w >> h;
		WW = W;
		HH = H;
		if (W < H) {
			huy = H;
			H = W;
			W = huy;
		}
		if (w < h) {
			huy = h;
			h = w;
			w = huy;
		}
		if (W < w || H < h) {
			out << -1; return 0;
		}
		long long k1=0, k2=0;
		while (W>w || H > h)
		{
			if (W > w) {
				if (W > (w * 2)) {
					W = W / 2 + W % 2; k1++;
				}
				else {
					W = w; k1++;
				}
			}
			if (H > h) {
				if (H > (h * 2)) {
					H = H / 2 + H % 2; k1++;
				}
				else {
					H = h; k1++;
				}
			}
		}
		k2 = k1 + 1;
		W = WW;
		H = HH;
		if (H >= w) {
			k2 = 0;
			huy = h;
			h = w;
			w = huy;
			while (W > w || H > h)
			{
				if (W > w) {
					if (W > (w * 2)) {
						W = W / 2 + W % 2; k2++;
					}
					else {
						W = w; k2++;
					}
				}
				if (H > h) {
					if (H > (h * 2)) {
						H = H / 2 + H % 2; k2++;
					}
					else {
						H = h; k2++;
					}
				}
			}
		}
		if (k1 < k2) out << k1; else out << k2;




		return 0;
	}



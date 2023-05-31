#include <fstream>

int check(int W, int w, int H, int h){
	if (w > W || h > H){
		return -1;
	}
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
	return counter;
}

int main(){
	std::ifstream IF("folding.in");
	std::ofstream OF("folding.out");
	int H, h, W, w;
	IF >> W >> H >> w >> h;
	int res0 = check(W, w, H, h);
	int res1 = check(W, h, H, w);
	if (res0 == -1){
		OF << res1; return 0;
	}
	if (res1 == -1){
		OF << res0; return 0;
	}
	if (res0 < res1){
		OF << res0;
	}
	else {
		OF << res1;
	}
	return 0;
}


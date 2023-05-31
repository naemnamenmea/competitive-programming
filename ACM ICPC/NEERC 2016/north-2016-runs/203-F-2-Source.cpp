#include <fstream>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;


int main() {
	string name = "folding";
	ifstream in(name + ".in");
	ofstream out(name + ".out");
	long W2, H2, w2, h2;
	in >> W2 >> H2 >> w2 >> h2;
	long W, H, w, h;
	W = max(W2, H2);
	H = min(W2, H2);
	w = max(w2, h2);
	h = min(w2, h2);
	long result = 0;
	if (W < w || H < h) {
		result = -1;
		out << result;
		return 0;
	}
	while (W > w) {
		W = W - W / 2;
		result++;
	}
	while (H > h) {
		H = H - H / 2;
		result++;
	}
	out << result;
	return 0;
}
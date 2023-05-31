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
	long W1, H1, w1, h1;
	W1 = max(W2, H2);
	H1 = min(W2, H2);
	w1 = max(w2, h2);
	h1 = min(w2, h2);
	long result = 0;
	long result2 = 0;
	W = W1; H = H1, h = h1, w = w1;
	if (W < w || H < h) {
		//result = -1;
		out << -1;
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
	W = W1; H = H1, h = h1, w = w1;
	while (W > h) {
		W = W - W / 2;
		result2++;
	}
	while (H > w) {
		H = H - H / 2;
		result2++;
	}
	out << min(result, result2);
	return 0;
}
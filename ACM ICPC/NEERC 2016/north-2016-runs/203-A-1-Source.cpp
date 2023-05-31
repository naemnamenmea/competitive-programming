#include <fstream>
#include <iostream>

using namespace std;

bool check(long double x1, long double y1, long double x2, long double y2, long long w, long long h) {
	if (x1 == w && x2 == w || x1 == 0 && x2 == 0)
		if (y1 < y2) {
		    long long ny1 = y1 - round(y1) >= 0 ? round(y1) + 1 : round(y1);
		    long long ny2 = y2 - round(y2) >= 0 ? round(y2) : round(y2) - 1;
			return ny2 - ny1 >= 0;
		}
		else {
			long long ny1 = y1 - round(y1) >= 0 ? round(y1) : round(y1) - 1;
			long long ny2 = y2 - round(y2) >= 0 ? round(y2) + 1: round(y2);
			return ny1 - ny2 >= 0;
		}
	
	if (y1 == h && y2 == h || y1 == 0 && y2 == 0)
		if (x1 < x2) {
		    long long ny1 = x1 - round(x1) >= 0 ? round(x1) + 1 : round(x1);
		    long long ny2 = x2 - round(x2) >= 0 ? round(x2) : round(x2) - 1;
		    return ny2 - ny1 >= 0;
		}
		else {
			long long ny1 = x1 - round(x1) >= 0 ? round(x1) : round(x1) - 1;
			long long ny2 = x2 - round(x2) >= 0 ? round(x2) + 1 : round(x2);
			return ny1 - ny2 >= 0;
		}

	return true;
}

long long getX(long double x1, long double x2, long double y1, long double y2, long long w) {

	if (y1 == y2) {
		if (x1 < x2) {
			return x1 - round(x1) >= 0 ? round(x1) + 1 : round(x1);
		}
		else {
			return x1 - round(x1) >= 0 ? round(x1) : round(x1) - 1;
		}
	}
	else
		return w;
}

int main() {
	
    ifstream in("anniversary.in");
	ofstream out("anniversary.out");
	long double w, h, ax, ay, bx, by;
	in >> w >> h >> ax >> ay >> bx >> by;

	for (long long i = 0; i <= h; i++) {
		if (ay == i || by == i) {
			continue;
		}
		long double xw = ax * (h - i) / (ay - i);
		long double x0 = ax * (-i) / (ay - i);
		long double yh = w / ax * (ay - i) + i;
		long double Y, X;
		if (xw >= 0 && xw < w) {
			Y = h;
			X = xw;
		}
		else if (i != 0 && x0 >= 0 && x0 <= w) {
			Y = 0;
			X = x0;
		}
		else if (yh >= 0 && yh <= h){
			Y = yh;
			X = w;
		}
		else
			continue;

		xw = bx * (h - i) / (by - i);
		x0 = bx * (-i) / (by - i);
		yh = w / bx * (by - i) + i;
		long double Y2, X2;
		if (xw >= 0 && xw < w) {
			Y2 = h;
			X2 = xw;
		}
		else if (i != 0 && x0 >= 0 && x0 <= w) {
			Y2 = 0;
			X2 = x0;
		}
		else if (yh >= 0 && yh <= h){
			Y2 = yh;
			X2 = w;
		}
		else
			continue;

		if (check(X, Y, X2, Y2, w, h)) {
			out << "0 " << i << " " << getX(X, X2, Y, Y2, w) << " " << getX(Y,Y2, X, X2, h);
			return 0;
		}
		
	}
	

	for (long long i = 0; i <= w; i++) {
		if (ax == i || bx == i) {
			continue;
		}
		
		long double y0 = (-i) / (ax - i) * ay;
		long double x0 = h * (ax - i) / ay + i;
		long double yw = (w - i) / (ax - i) * ay;
		long double Y, X;
		if (i != 0 && y0 >= 0 && y0 < h) {
			Y = y0;
			X = 0;
		}
		else if (x0 >= 0 && x0 <= w) {
			Y = h;
			X = x0;
		}
		else if (yw >= 0 && yw <= w){
			Y = yw;
			X = w;
		}
		else
			continue;

		y0 = (-i) / (bx - i) * by;
		x0 = h * (bx - i) / by + i;
		yw = (w - i) / (bx - i) * by;
		long long Y2, X2;
		if (y0 >= 0 && y0 < h) {
			Y2 = y0;
			X2 = 0;
		}
		else if (x0 >= 0 && x0 <= w) {
			Y2 = h;
			X2 = x0;
		}
		else if (yw >= 0 && yw <= w){
			Y2 = yw;
			X2 = w;
		}
		else
			continue;

		if (check(X, Y, X2, Y2, w, h)) {
			out << i << " 0 " << getX(X, X2, Y, Y2, w) << " " << getX(Y, Y2, X, X2, h);
			return 0;
		}

	}

	out << "WRONG"; 
	return 0;
}
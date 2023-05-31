#include <bits/stdc++.h>

//#define Otkrytka_i_konvert
#ifdef Otkrytka_i_konvert

#ifdef LOCAL_KONTROL
#define IN "acmp/INPUT.TXT"
#define OUT "acmp/OUTPUT.TXT"
#else
#define IN "INPUT.TXT"
#define OUT "OUTPUT.TXT"
#endif

using namespace std;

struct point2d
{
	double x;
	double y;
	point2d() {}
	point2d(double x, double y) : x(x), y(y) {}
	point2d operator*(double k) {
		return point2d(x*k, y*k);
	}
	friend point2d operator-(const point2d& a, const point2d& b) {
		return point2d(a.x - b.x, a.y - b.y);
	}
	friend point2d operator+(const point2d& a, const point2d& b) {
		return point2d(a.x + b.x, a.y + b.y);
	}
	friend double operator~(const point2d& p) {
		return sqrt(p.x*p.x + p.y*p.y);
	}

	friend ostream& operator<<(ostream& os, const point2d& p) {
		os << "x = " << p.x << " ; y = " << p.y << endl;
		return os;
	}
	friend istream& operator>>(istream& is, point2d& p) {
		is >> p.x >> p.y;
		return is;
	}
};

//point2d findPointInSegment(point2d& m1, point2d& m2, double lambda) {
//	return point2d(
//		(m1.x + lambda*m2.x) / (1 + lambda),
//		(m1.y + lambda*m2.y) / (1 + lambda)
//	);
//}
//point2d findPointOutOfSegment(point2d& m0, point2d& m1, double lambda) {
//	return point2d(
//		(m0.x*(1 + lambda) - m1.x) / lambda,
//		(m0.y*(1 + lambda) - m1.y) / lambda
//	);
//}

point2d getPoint(const point2d& beginPoint, const point2d& dirVec, double segmentLen) {
	point2d vec = dirVec;
	return point2d(
		segmentLen*vec.x / ~vec,
		segmentLen*vec.y / ~vec
	) + beginPoint;
}

int main() {
	ifstream ifs(IN);
	ofstream ofs(OUT);
	cin.rdbuf(ifs.rdbuf());
	cout.rdbuf(ofs.rdbuf());

	point2d in, out;
	cin >> in >> out;

	if (in.x < in.y)
		swap(in.x, in.y);
	if (out.x < out.y)
		swap(out.x, out.y);

	bool res = true;
	if (in.x > out.x || in.y > out.y) {
		// if(~out < in.x) res = false; // дальше не смотрим

		point2d tmp = getPoint(point2d(0, 0), out, (~out + in.x) / 2.);
		point2d ext = getPoint(tmp, point2d(-out.y, out.x), in.y / 2.);
		if (ext.y > out.y)
			res = false;

		cerr << tmp << endl << ext << endl << out;
	}
	cout << (res ? "Possible" : "Impossible") << endl;
}

#endif // Otkrytka_i_konvert
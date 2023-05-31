#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

#define EPS 1e-6

struct Point {
	double x;
	double y;
	Point() {}
	Point(double x, double y)
		:x(x), y(y)
	{}
};

istream& operator >> (istream& is, Point& p) {
	double x, y;
	cin >> x >> y;
	p.x = x;
	p.y = y;
	return is;
}

struct Line {
	double k;
	double b;

	Line() {}

	Line(double k, double b)
		:k(k), b(b)	
	{}

	Line(const Point& p1, const Point& p2)
	{
		k = (p2.y - p1.y) / (p2.x - p1.x);
		b = (p1.x*p1.y + p1.x*p2.y) / (p2.x - p1.x) + p1.y;
	}

	bool Contains(const Point& p) {
		return abs(p.x*k + b - p.y) < EPS;
	}
};

int main()
{
#ifdef KONTROL_LOCAL
	ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
	//ofstream ofs("output.txt"); cout.rdbuf(ofs.rdbuf());
#endif
	int n;
	vector<Line> unique;
	cin >> n;
	while (n--) {
		Point p;
		cin >> p;
		bool res = false;
		for (const auto& v : unique) {
			if () {

			}
		}
	}

	return 0;
}
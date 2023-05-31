#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
	long long x;
	long long y;
};

long double getS(Point p1, Point p2, Point p3) {
	long double a = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	long double b = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
    long double c = sqrt(pow(p3.x - p1.x, 2) + pow(p3.y - p1.y, 2));

    long double p = (a + b + c) / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

long double getS(vector<Point> point) {
	long double other = 0;
	Point p = point.at(point.size() - 1);
	Point f = point.at(0);
	Point s = point.at(point.size() - 2);
	if (point.size() > 3) {
		point.pop_back();
		other = getS(point);
	}
    
    return other + getS(p,f,s);
}

int main() {
	string name = "integral";
	ifstream in(name + ".in");
	ofstream out(name + ".out");
	long long res = 0;
	long double eps = 0.00000000001;
	long n;
    in >> n;
   
    vector<Point> points = vector<Point>();

	for (long i = 0; i < n; i++)
	{
		points.push_back(Point());
		in >> points[i].x >> points[i].y;
	}
	long double s = getS(points);
	if (abs(round(s) - s) > eps) {
		out << 0;
		return 0;
	}
	
	for (long i = 0; i < n - 1; i++)
	{
		
		for (long j = i + 2; j < n - (i == 0); j++)
		{
			vector<Point> nv = vector<Point>();
			for (long k = i; k <= j; k++) {
				nv.push_back(points.at(k));
			}
			long double sum = getS(nv);
			if (abs(round(sum) - sum) < eps) {
				/*vector<Point> nv = vector<Point>();
				for (int k = 0; k <= i; k++) {
					nv.push_back(points.at(k));
				}
				for (int k = j; k < n; k++) {
					nv.push_back(points.at(k));
				}
				long double sum2 = getS(nv);
				if (abs(round(sum2) - sum2) < eps) {*/
					res++;
				//}
			}
		}
	}
    
	out << res;
	return 0;
} 
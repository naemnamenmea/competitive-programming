#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <iterator>
#include <set>
#include <algorithm>
struct point{
	long long x, y;
};
long long cw(point& a, point& b, point& c){
	return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y);
}

using namespace std;
int main(){
	ifstream in("anniversary.in");
	ofstream out("anniversary.out");
	long long w, h;
	in >> w >> h;
	point p0, p1,p2,p3;
	in >> p1.x >> p1.y >> p2.x >> p2.y;
	p0.x = 0;
	p0.y = 0;
	p3.x = 1;
	p3.y = h;
	bool b = false;
	for (int i = 1; i < w; ++i){
		p3.x = i;
		p3.y = h;
		if ((cw(p0, p1, p3) > 0 && cw(p0, p2, p3) < 0) || (cw(p0, p1, p3) < 0 && cw(p0, p2, p3) > 0)){
			b = true;
			break;
		}
	}
	if (!b){
		for (int i = 1; i < h; ++i){
			p3.x = w;
			p3.y = i;
			if ((cw(p0, p1, p3) > 0 && cw(p0, p2, p3) < 0) || (cw(p0, p1, p3) < 0 && cw(p0, p2, p3) > 0)){
				b = true;
				break;
			}
		}
	}
	if (!b)
		p0.x = w;
	if (!b){
		for (int i = w-1; i>=0; --i){
			p3.x = i;
			p3.y = h;
			if ((cw(p0, p1, p3) > 0 && cw(p0, p2, p3) < 0) || (cw(p0, p1, p3) < 0 && cw(p0, p2, p3) > 0)){
				b = true;
				break;
			}
		}
	}
	if (!b){
		for (int i = h-1; i >= 0; --i){
			p3.x = 0;
			p3.y = i;
			if ((cw(p0, p1, p3) > 0 && cw(p0, p2, p3) < 0) || (cw(p0, p1, p3) < 0 && cw(p0, p2, p3) > 0)){
				b = true;
				break;
			}
		}
	}
	if (b)
		out << p0.x << " " << p0.y << " " << p3.x << " " << p3.y;
	in.close();
	out.close();
	return 0;
}


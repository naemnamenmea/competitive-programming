// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <math.h>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("anniversary.in");
	out.open("anniversary.out");
	int w, h, ax, ay, bx, by;
	in >> w >> h >> ax >> ay >> bx >> by;
	int minx;
	if (ax < bx) {
		minx = ax;
	}
	else minx = bx;
	int miny;
	if (ay < by) {
		miny = ay;
	}
	else miny = by;
	for (int i = 0; i <= w / 2 + 1; i++){
		for (int j = minx; j <= w; j++){
			if(j<w) {int k = h;
			double aso = asin(ay / sqrt(pow(ax - i, 2) + pow(ay, 2)));
			double eso = asin(k / sqrt(pow(j - i, 2) + pow(k, 2)));
			double bso = asin(by / sqrt(pow(bx - i, 2) + pow(by, 2)));
			if (((eso > aso) && (eso < bso)) || ((eso<aso) && (eso>bso))){
				out << i << " " << 0 << " " << j << " " << k;
				return(0);
			}
			}
			if (j == w) for (int k = h; k >=miny; k--){
				double aso = asin(ay / sqrt(pow(ax - i, 2) + pow(ay, 2)));
				double eso = asin(k / sqrt(pow(j - i, 2) + pow(k, 2)));
				double bso = asin(by / sqrt(pow(bx - i, 2) + pow(by, 2)));
				if (((eso>aso) && (eso < bso)) || ((eso<aso) && (eso>bso))){
					out << i <<" "<< 0<<" " << j << " "<< k;
					return(0);
				}
			}
		}
	}
	in.close();
	out.close();
	return 0;
}
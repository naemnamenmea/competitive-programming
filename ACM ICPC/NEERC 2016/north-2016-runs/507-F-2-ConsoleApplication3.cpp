#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	ifstream in("folding.in");
	ofstream out("folding.out");
	long long x1, y1, x2, y2,x,y,x3,y3;
	in >> x1 >> y1 >> x2 >> y2;
	int k1 = 0,k2=0,k3=0,k4=0;
	if (x1 < y1)
		swap(y1, x1);
	if (x2 < y2)
		swap(y2, x2);
	if ((x1 < x2 && y1 < x2) || (x1 < y2 && y1 < y2)){
		out << "-1";
		return 0;
	}
	x = x1;
	y = y1;
	x3 = x2;
	y3 = y2;
	while (x2 != x1){
			if (x2 * 2 >= x1){
				x1 = x2;
			}
			else if (x1 & 1){
				x1 >>= 1;
				++x1;
			}
			else{
				x1 >>= 1;
			}
			++k1;
	}
	x1=x;
	y1=y;
	x2 = x3;
	y2=y3;
	while (y2 != x1){
		if (y2 * 2 >= x1){
			x1 = y2;
		}
		else if (x1 & 1){
			x1 >>= 1;
			++x1;
		}
		else{
			x1 >>= 1;
		}
		++k2;
	}
	x1 = x;
	y1 = y;
	x2 = x3;;
	y2 = y3;
	while (y2 != y1){
		//if (y2 * 2 < x1){
		if (y2 * 2 >= y1){
			y1 = y2;
		}
		else if (y1 & 1){
			y1 >>= 1;
			++y1;
		}
		else{
			y1 >>= 1;
		}
		++k3;
		//}
	}
	x1 = x;
	y1 = y;
	x2 = x3;
	y2 = y3;
	while (y1 != x2){
		//if (y2 * 2 < x1){
		if (y1 * 2 >= x2){
			x2 = y1;
		}
		else if (y1 & 1){
			y1 >>= 1;
			++x2;
		}
		else{
			x2 >>= 1;
		}
		++k4;
		//}
	}
	out << min(k1 + k3, k2 + k4);
    in.close();
	out.close();
	return 0;
}


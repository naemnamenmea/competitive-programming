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
	long long x1, y1, x2, y2;
	in >> x1 >> y1 >> x2 >> y2;
	int k = 0;
	if (x1 < y1)
		swap(y1, x1);
	if (x2 < y2)
		swap(y2, x2);
	if ((x1 < x2 && y1 < x2) || (x1 < y2 && y1 < y2)){
		out << "-1";
		return 0;
	}
	while (x2 != x1){
		//if (y2 * 2 < x1){
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
			++k;
		//}
	}
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
		++k;
		//}
	}
	out << k;
    in.close();
	out.close();
	return 0;
}


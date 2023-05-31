#include <fstream>

using namespace std;

//long long cont(long long max, long long maxend, long long c){
//	while (max>maxend){
//		if (max <= 2 * maxend) max = maxend;
//		else {
//			if (max % 2 != 0) {
//				max /= 2;
//				max++;
//			}
//			else max /= 2;
//		}
//		c++;
//	};
//	return c;
//};
int main(){

	long long w, h, wend, hend;
	long long c=0;
	ifstream in("folding.in");
	ofstream out("folding.out");
	in >> w >> h >> wend >> hend;
	long long max, min, maxend, minend;
	max = w;
	min = h;
	if (h > max){ max = h; min = w; }

	maxend = wend;
	minend = hend;
	if (hend > maxend){ maxend = hend; minend = wend; }
	int y = 0;
	if (max == maxend && min == minend){
		out << 0;
		return 0;
	}
	if (maxend > max){
		out << -1; 
		return 0;
	}
	long long o;
	while (max > maxend)
	{
		if (max <= 2 * maxend) max = maxend;
		else {
			if (max % 2 != 0) {
				max /= 2;
				max++;
			}
			else max /= 2;
		}
		c++;
		if (max < min){ o = min; min = max; max = o; }

	};

	while (minend<min)
	   {
		if (min <= 2 * minend) min = minend;
		else {
			if (min % 2 != 0) {
				min /= 2;
				min++;
			}
			else min /= 2;
		}
		c++;
	}
	/*if (maxend != max){
		c = cont(max, maxend, c);
	}

	if (minend > min){
		out << -1;
		return 0;
	}
	if(minend!=min)
	c = cont(min, minend, c);

*/
	out << c; 
	return 0;
}


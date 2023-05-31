#include <fstream>

using namespace std;
int main(){

	long long w, h, wend, hend;
	int c=0;
	ifstream in("folding.in");
	ofstream out("folding.out");
	in >> w >> h >> wend >> hend;
	long long max, min, maxend, minend;
	max = w;
	if (h > max){ max = h; min = w; }
	else{ min = h; max = w; }

	maxend = wend;
	if (hend > maxend){ maxend = hend; minend = wend; }
	else{ minend = hend; maxend = wend; }
	int y = 0;


	if (maxend > max){
		out << -1; 
		return 0;
	}
	while (max>maxend){
		if (max < 2 * maxend) { max = maxend; }
		else {
			if (max % 2 != 0) {
				max /= 2;
				max++;
			}else
			max /= 2;
		}
	 c++;
	};

	if (minend > min){
		out << -1;
		return 0;
	}

	while (min>minend){
		if (min< 2 * minend) { min = minend; }
		else{
			if (min % 2 != 0) {
				min /= 2;
				min++;
			}
			else min /= 2;
		}
		c++;
	}


		out << c; return 0;
}

#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	ifstream fin("folding.in");
	ofstream fout("folding.out");

	int sw, sh, ew, eh;
	fin >> sw >> sh >> ew >> eh;

	if (ew > sw && ew > sh || eh > sw && eh > sh){
		fout << -1;
		return 0;
	}
	int proc = 1;
	int folds = 0;

	int halfw, halfh;
	if (ew < eh)
		swap(&ew, &eh);

	while (proc>=0) {
		proc = 0;

		if (sw < sh)
			swap(&sw, &sh);
		halfw = sw / 2;// cout << halfw << " ";
		halfh = sh / 2;//  cout << halfh << " ";

		if (sw != ew) {
			if (halfw > ew) {
				sw = sw - halfw;
				proc ++;
			}
			else {
				sw = ew;
				proc --;
			}
			folds++;
		}
		else proc--;
		
		if (sh != eh) {
			if (halfh > eh) {
				sh = sh - halfh;
				proc ++;
			}
			else{
				sh = eh;
				proc --;
			}
			folds++;
		}
		else proc--;

	}
	fout << folds;
	//system("pause");
	return 0;
}
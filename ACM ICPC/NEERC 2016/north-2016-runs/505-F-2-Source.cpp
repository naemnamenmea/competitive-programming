#include <fstream>

using namespace std;

int main() {
	ifstream fin;
	fin.open("folding.in");

	long wa, ha, wb, hb;
	fin >> wa >> ha >> wb >> hb;

	fin.close();

	int x;
	if (wa < ha) {
		x = wa;
		wa = ha;
		ha = x;
	}
	if (wb < hb){
		x = wb;
		wb = hb;
		hb = x;
	}

	int rez = -1;
	if ((wa >= wb) & (ha >= hb)) {
		rez++;
		double y = wa;
		while (y / 2 >= wb){
			y = y / 2;
			rez++;
		}
		if (y != wb) rez++;
		y = ha;
		while (y / 2 >= hb){
			y = y / 2;
			rez++;
		}
		if (y != hb) rez++;
	}

	int rez2 = -1;
	if ((wa >= hb) & (ha >= wb)) {
		rez2++;
		double y = wa;
		while (y / 2 >= hb){
			y = y / 2;
			rez2++;
		}
		if (y != hb) rez2++;
		y = ha;
		while (y / 2 >= wb){
			y = y / 2;
			rez2++;
		}
		if (y != wb) rez2++;
	}

	if ( (rez2 < rez) & (rez2 != -1) ) rez = rez2;

	ofstream fout;
	fout.open("folding.out");
	fout << rez;
	fout.close();

	return 0;
}
	
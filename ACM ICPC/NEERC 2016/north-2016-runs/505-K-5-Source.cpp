#include <fstream>

using namespace std;

bool GreaterOrEq(int year1, int month1, int day1, int year2, int month2, int day2);

int main() {
	ifstream fin;
	fin.open("king.in");
	int kd, km, ky;
	fin >> kd >> km >> ky;
	ky = ky - 18;
	int n;
	fin >> n;
	int miny = -1, minm = 0, mind = 0, mini = -1, cy, cm, cd;
	for (int i = 1; i <= n; i++){
		fin >> cd >> cm >> cy;
		if (!GreaterOrEq(cy, cm, cd, ky, km, kd))
			if (!GreaterOrEq(miny, minm, mind, cy, cm, cd)){
				mind = cd;
				minm = cm;
				miny = cy;
				mini = i;
			}

		
	}

	ofstream fout;
	fout.open("king.out");
	fout << mini;
	fout.close();

}

bool GreaterOrEq(int year1, int month1, int day1, int year2, int month2, int day2){
	if (year1 > year2) return true;
	if (year1 < year2) return false;
	if (month1 > month2) return true;
	if (month1 < month2) return false;
	if (day1 > day2) return true;
	if (day1 < day2) return false;
	return false;
	}
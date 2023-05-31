#include <fstream>
#include <vector>

using namespace std;

struct Date {
	int d;
	int m;
	int y;
};

int main() {
	ifstream in("king.in");
	ofstream out("king.out");
	Date king, temp, kek;
	vector<Date> sons;
	in >> king.d >> king.m >> king.y;
	int n, res = -2;
	in >> n;
	temp.d = 1; temp.m = 1; temp.y = -1;
	for (int i = 0; i < n; i++){
		in >> kek.d >> kek.m >> kek.y;
		if (
			(
			(king.y - kek.y > 18) ||
				(king.y - kek.y == 18 && king.m > kek.m) || 
				(king.y - kek.y == 18 && king.m == kek.m && king.d>=kek.d)
				)){
			res = res;
			if ((
				(
				(temp.y < kek.y) ||
				(temp.y == kek.y && temp.m > kek.m) ||
				(temp.y == kek.y && temp.m == kek.m && temp.d > kek.d)
				)
				)
				){
				res = i;
				temp.d = kek.d;
				temp.m = kek.m;
				temp.y = kek.y;
			}
		}
	}
	out << res+1;
	return 0;
}